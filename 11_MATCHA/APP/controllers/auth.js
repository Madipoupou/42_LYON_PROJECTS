// Controller of all the auth stuff (Authentication, retrieving data, etc.)

const User = require('../models/user');
const UserInterest = require('../models/userInterest');
const Interest = require('../models/interest');
const bcrypt = require('bcrypt');
const jwt = require('jsonwebtoken');
const throwError = require('../util/error');
const nodeMailer = require('nodemailer');
const hidden = require('./../util/hidden');

// Mail initialization
let transporter = nodeMailer.createTransport({
    host: 'smtp.gmail.com',
    port: 465,
    secure: true,
    auth: {
        user: 'garbage.10142@gmail.com',
        pass: hidden.mailPassword
    }
});

// Register an user in the DB
exports.signup = ((req, res, next) => {
    const mail = req.body.mail;
    const uname = req.body.uname;
    const fname = req.body.fname;
    const lname = req.body.lname;
    const pwd = req.body.pwd;

    bcrypt.hash(pwd, 12)
        .then(hash => {
            const user = new User(mail, uname, fname, lname, hash);
            return user.create();
        })
        .then(result => User.findByUsername(uname))
        .then(row => {
            // Activate email
            let activateUrl = 'http://localhost:3000/activate?username=' + uname + '&token=' + row.usr_activationToken;
            let mailOptions = {
                from: '"MATCHA" <garbage.10142@gmail.com>',
                to: mail,
                subject: 'Matcha - Activer votre compte',
                html:
                    '<h3>Bienvenue sur matcha!</h3><br /> ' +
                    '<p>Vous êtes bien inscrit sur matcha.<br />' +
                    'Pour activer votre compte, veuillez cliquer sur le lien suivant (ou le copier dans votre navigateur):<br />' +
                    activateUrl + '</p>'
            };
            return (transporter.sendMail(mailOptions, (error, info) => {
                if (error) {
                    throwError('Mail impossible à envoyer', 400);
                } else {
                    res.status(201).json({
                        message: 'Votre compte a été créé, vérifiez vos mails pour activer votre compte'
                    });
                }
            }));
        })
        .catch(err => next(err));
});

// Feed user's profile with given information - deals with undefined fields - image not managed for the moment
// The interests are received as an array - We create a promise for each array and deal with them one by one
exports.fillup = ((req, res, next) => {
    const gender = req.body.gender;
    const orientation = req.body.orientation;
    const bio = req.body.bio;
    const age = req.body.age;
    const interests = req.body.interests;
    const user = new User();

    user.populate(req.userId)
        .then(() => {
            if (gender)
                user.gender = gender;
            if (orientation)
                user.orientation = orientation;
            if (bio)
                user.bio = bio;
            if (age)
                user.age = age;
        })
        .then(() => {
            return user.update();
        })
        .then(() => {
            if (!interests) {
                return;
            } else {
                UserInterest.removeAll(req.userId)
                    .then(result => {
                        const promises = [];
                        for (let interest of interests) {
                            promises.push(
                                Interest.add(interest)
                                    .then(interestId => {
                                        if (!interestId)
                                            throwError('Intérêt mal formaté', 422);
                                        return UserInterest.add(req.userId, interestId);
                                    })
                            );
                        }
                        return Promise.all(promises);
                    })
            }

        })
        .then(() => {
            if (req.position) {
                return (User.updatePosition(req.userId, req.position));
            }
        })
        .then(() => {
            res.status(201).json({
                message: 'Informations mises à jour'
            });
        })
        .catch(err => next(err));
});

// Management of the login
// Check if user information are correct and the generating a unique token available for one hour
// We send back the token (NEED TO SEE IF WE CAN "AUTOREFRESH" THE TOKEN)
exports.login = ((req, res, next) => {
    if (!req.body.uname || !req.body.pwd)
        throwError('Champ(s) manquant(s)', 422);
    let user;
    User.findByUsername(req.body.uname)
        .then((userDb) => {
            user = userDb;
            if (!user)
                throwError('Utilisateur inexistant', 422);
            if (userDb.usr_active === 0)
                throwError('Vous devez activer votre compte !', 400);
            if (userDb.usr_report === 1) {
                throwError('Votre compte a été signalé et doit être vérifié, contactez l\'administrateur');
            }
            return bcrypt.compare(req.body.pwd, user.usr_pwd);
        })
        .then(match => {
            if (!match)
                throwError('Mauvais mot de passe', 422);
            const token = jwt.sign(
                { userId: user.usr_id, username: user.usr_uname },
                ';R)LK4nh=]POwYtcJy=u5aEEI',
                { expiresIn: '1h' }
            );
            res.status(200).json({
                token: token,
                userId: user.usr_id,
                expiration: 3600,
                message: 'Vous êtes maintenant connecté'
            });
        })
        .catch(err => next(err));
});

// Update the signup data into the database
// Using req.body arguments - if one is empty, then it is not updated
// If pwd is defined, it updates the password of the user else it does not deal with pasword
exports.updateSignup = (req, res, next) => {
    const userId = req.userId;
    const uname = req.uname;
    const fname = req.fname;
    const lname = req.lname;
    const mail = req.mail;
    const pwd = (req.pwd ? req.pwd : '');

    bcrypt.hash(pwd, 12)
        .then(hash => {
            if (pwd === '') {
                return (User.updateSignup(userId, uname, fname, lname, mail, ''));
            } else {
                return (User.updateSignup(userId, uname, fname, lname, mail, hash));
            }
        })
        .then(result => {
            res.status(200).json({
                message: 'Profil mis à jour'
            });
        })
        .catch(err => next(err));
};

// Activate the account in the database
// Using req.body arguments: uname AND activateToken
exports.activate = (req, res, next) => {
    const activateToken = req.body.token;
    const uname = req.body.username;

    if (!uname || !activateToken) {
        throwError('Les champs uname et activateToker sont requis', 422);
    }
    User.activate(uname, activateToken)
        .then(result => {
            res.status(200).json({
                message: 'Votre compte a été activé'
            });
        })
        .catch(err => next(err));
};

// PUT '/auth/resetPwd' -> Asking the server to send an email for resetting
exports.putResetPwd = (req, res, next) => {
    const mail = req.mail;

    User.findByMail(mail)
        .then(user => {
            // Reset email
            let resetUrl = 'http://localhost:3000/reset?username=' + user.usr_uname + '&token=' + user.usr_resetToken;
            let mailOptions = {
                from: '"MATCHA" <garbage.10142@gmail.com>',
                to: mail,
                subject: 'Matcha - Renouveler votre mot de passe',
                html:
                    '<h3>Bienvenue sur matcha!</h3><br /> ' +
                    '<p>Vous avez demandé une réinitialisation de votre mot de passe.<br />' +
                    'Pour poursuivre cette démarche, veuillez cliquer sur le lien suivant (ou le copier dans votre navigateur):<br />' +
                    resetUrl + '</p>'
            };
            return (transporter.sendMail(mailOptions, (error, info) => {
                if (error) {
                    throwError('Mail impossible à envoyer', 400);
                } else {
                    res.status(201).json({
                        message: 'Un mail de réinitialisation a été envoyé'
                    });
                }
            }));
        })    
        .catch (err => next(err));
}

// POST '/auth/resetPwd' -> Sending the data to the server to change the password in the DB
exports.postResetPwd = (req, res, next) => {
    const uname = req.body.username;
    const pwd = req.body.pwd;
    bcrypt.hash(pwd, 12)
        .then(hash => {
            return (User.updatePwd(uname, hash));
        })
        .then(result => {
            res.status(201).json({
                message: 'Mot de passe mis à jour'
            });
        })
        .catch (err => next(err));
}