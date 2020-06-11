// Controller of the interactions

const Block = require('./../models/interactions/block');
const Report = require('./../models/interactions/report');
const Like = require('./../models/interactions/like');
const Visit = require('./../models/interactions/visit');
const User = require('../models/user');
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

// PUT '/interact/block'
// Record a block in the DB
exports.putBlock = (req, res, next) => {
    const userId = req.userId;
    const otherId = req.body.otherId;

    Block.addBlock(userId, otherId)
        .then(result => {
            res.status(201).json({
                message: "Block added"
            });
        })
        .catch(err => next(err));
};

// DELETE '/interact/block'
// Delete a block from the DB
exports.deleteBlock = (req, res, next) => {
    const userId = req.userId;
    const otherId = req.body.otherId;

    Block.deleteBlock(userId, otherId)
        .then(result => {
            res.status(202).json({
                message: "Block removed"
            });
        })
        .catch(err => next(err));
};

// PUT '/interact/like'
// Record a like in the DB and a match if necessary
exports.putLike = (req, res, next) => {
    const userId = req.userId.toString();
    const otherId = req.body.otherId;

    Like.addLike(userId, otherId)
        .then(result => {
            res.status(202).json({
                message: "Like added"
            });
        })
        .catch(err => next(err));
};

// DELETE '/interact/like'
// Remove a like from DB and the corresponding match if necessary
exports.deleteLike = (req, res, next) => {
    const userId = req.userId;
    const otherId = req.body.otherId;

    Like.deleteLike(userId, otherId)
        .then(result => {
            res.status(202).json({
                message: "Like removed"
            });
        })
        .catch(err => next(err));
};

// PUT '/interact/report'
// Record a report in the DB
exports.putReport = (req, res, next) => {
    const userId = req.userId;
    const otherId = req.body.otherId;

    Report.addReport(userId, otherId)
        .then(_ => {
            return (Report.countReport(otherId));
        })
        .then(res => {
            if (res['nb'] >= 5) {
                return (User.reportLimit(otherId)
                    .then(_ => User.findById(otherId))
                    .then(user => {
                        // Reported email
                        let mailOptions = {
                            from: '"MATCHA" <garbage.10142@gmail.com>',
                            to: user.usr_email,
                            subject: 'Matcha - Compte bloqué',
                            html:
                                '<h3>Bonjour!</h3><br /> ' +
                                '<p>De nombreux utilisateurs ont signalé votre profil comme étant faux.<br />' +
                                'Vous avez donc été bloqué. Pour débloquer votre compte, veuillez envoyer une photocopie de votre carte d\'identité à l\'adresse email suivante:<br />' +
                                'garbage.10142@gmail.com<br />' +
                                'Merci de votre compréhension.</p>'
                        };
                        return (transporter.sendMail(mailOptions, (error, info) => {
                            if (error) {
                                throwError('Mail impossible à envoyer', 400);
                            }
                        }))
                    })
                );
            } else {
                return ('ok');
            }
        })
        .then(_ => {
            res.status(201).json({
                message: "Report added"
            });
        })
        .catch(err => next(err));
};

// DELETE '/interact/report'
// Remove a report from the DB
exports.deleteReport = (req, res, next) => {
    const userId = req.userId;
    const otherId = req.body.otherId;

    Report.deleteReport(userId, otherId)
        .then(result => {
            res.status(202).json({
                message: "Report removed"
            });
        })
        .catch(err => next(err));
};

// PUT '/interact/visit'
// Record a visit in the DB - if first visit the user is created else the user counter is increased
// If id of visitor is the same than id of visited, nothing happens
exports.putVisit = (req, res, next) => {
    const userId = req.userId;
    const otherId = req.body.otherId;

    Visit.addVisit(userId, otherId)
        .then(result => {
            res.status(202).json({
                message: "Visit Added"
            });
        })
        .catch(err => next(err));
};

// Get all the visits of the connected user
exports.getVisits = (req, res, next) => {
    const userId = req.userId;

    Visit.getVisits(userId)
    .then(rows => {
        const promises = rows.map(row => {
            return User.findById(row.other_id).then(user => {
                row.username = user.usr_uname;
            });
        });
        return Promise.all(promises).then(_ => rows);
    })
    .then(users => {
        const history = users.map(user => {
            return {
                id: user.other_id,
                uname: user.username,
                total: user.total,
                date: user.date
            };
        });
        return history;
    })
    .then(history => res.status(200).json({history}))
    .catch(err => next(err));
    
};

// Get all the users blocked by the connected user
exports.getBlocks = (req, res, next) => {
    const userId = req.userId;

    Block.getBlocks(userId)
    .then(rows => {
        const promises = rows.map(row => {
            return User.findById(row.other_id).then(user => {
                row.username = user.usr_uname;
            });
        });
        return Promise.all(promises).then( _ => rows);
    })
    .then(users => {
        const blocks = users.map(user => {
            return {
                id: user.other_id,
                uname: user.username,
                date: user.date
            }   
        });
        return blocks;
    })
    .then(blocks => res.status(200).json({blocks}))
    .catch(err => next(err));
};

// Get all the users who liked the connected user
exports.getLikes = (req, res, next) => {
    const userId = req.userId;

    Like.getLikes(userId)
    .then(rows => {
        const promises = rows.map(row => {
            return User.findById(row.other_id).then(user => {
                row.username = user.usr_uname;
            });
        });
        return Promise.all(promises).then( _ => rows);
    })
    .then(users => {
        const likes = users.map(user => {
            return {
                id: user.other_id,
                uname: user.username,
                date: user.date
            }   
        });
        return likes;
    })
    .then(likes => res.status(200).json({likes}))
    .catch(err => next(err));
};
