// Class used for validation of inputs

const User = require('../models/user');
const throwError = require('../util/error');

class Validation {
    // Validation constructor
    constructor(mail, uname, fname, lname, pwd, pwdConfirm) {
        this.mail = mail;
        this.uname = uname;
        this.fname = fname;
        this.lname = lname;
        this.pwd = pwd;
        this.pwdConfirm = pwdConfirm;
    }

    /****************************************** */
    /*                  SIGNUP                  */
    /****************************************** */

    // Mail validation (format, etc.)
    static fMail(email) {
        const regex = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/gm;
        if (regex.test(email) === false)
            throwError('L\'email entré n\'est pas correct', 422);
        return User.findByMail(email);
    }

    // Username validation
    static fUsername(uname) {
        if (uname.length < 3)
            throwError('Le nom d\'utilisateur doit posséder au moins 3 caractères', 422);
        const regex = /^[a-zA-Z0-9]$/;
        for (let char of uname) {
            if (regex.test(char) === false)
                throwError('Le nom d\'utilisateur doit être composé uniquement de chiffres et de lettres', 422);
        }
        return User.findByUsername(uname);
    }

    // Password validation (at least: -8 chars; -one upper; -one digit)
    static fPassword(pwd) {
        const regex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9])(?=.{8,})/;
        return regex.test(pwd);
    }

    // Password and password confirmation validation
    fPasswordConfirm() {
        return (this.pwd === this.pwdConfirm);
    }

    // Signup global validation using the above tools
    signUp() {
        if (!this.mail || !this.uname || !this.fname || !this.lname || !this.pwd || !this.pwdConfirm)
            throwError('Champ manquant', 422);
        if (this.mail.length >= 254 || this.uname.length >= 254 || this.fname.length >= 254 || this.lname.length >= 254 || this.pwd.length >= 254)
            throwError('Longueur de champ excessive', 422);
        if (Validation.fPassword(this.pwd) === false)
            throwError('Votre mot de passe doit contenir au moins 8 caractères dont une lettre minuscule, une lettre majuscule et un chiffre', 422);
        if (this.fPasswordConfirm() === false)
            throwError('Les deux mots de passe entrés sont différents', 422);
        return Validation.fUsername(this.uname)
            .then(user => {
                if (user)
                    throwError('Ce nom d\'utilisateur est déjà utilisé', 422);
                return Validation.fMail(this.mail);
            })
            .then(user => {
                if (user)
                    throwError('Cet email est déjà utilisé', 422);
            });
    }

    /****************************************** */
    /*                  FILLUP                  */
    /****************************************** */

    // Adding new attributes when users send information
    setVars(gender, orientation, bio, age, interests) {
        this.gender = gender;
        this.orientation = orientation;
        this.bio = bio;
        this.age = age;
        this.interests = interests;
    }

    // Gender validation
    fGender() {
        if (!this.gender)
            return true;
        return this.gender == 'male' || this.gender == 'female';
    }

    // Orientation validation
    fOrientation() {
        if (!this.orientation)
            return true;
        return this.orientation == 'hetero' || this.orientation == 'homo'
            || this.orientation == 'bi';
    }

    // Interests validation
    fInterests() {
        if (this.interests === undefined)
            return true;
        if (Array.isArray(this.interests) === false)
            return false;
        for (let interest of this.interests) {
            if (interest && typeof interest !== 'string')
                return false;
        }
        return true;
    }

    // Age validation
    fAge() {
        if (!this.age)
            return true;
        return +this.age >= 18 && +this.age < 100;
    }

    // FillUp global validation, using the above tools
    fillUp() {
        if (this.fGender() == false)
            throwError('Mauvais genre (êtes vous un robot ?)', 422);
        if (this.fOrientation() == false)
            throwError('Mauvaise orientation (êtes vous robotphile ?)', 422);
        if (this.fInterests() === false)
            throwError('Intérêts mal formatés');
        if (this.fAge() === false)
            throwError('Mauvais âge', 422);
        if (this.interests) {
            for (let interest of this.interests) {
                if (interest.length >= 254)
                    throwError('Longueur de champ excessive', 422);
            }
        }
    }
}

module.exports = Validation;
