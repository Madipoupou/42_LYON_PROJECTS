/********************************************************************************
 *  DATABASE fake data creation - JS version
 *  Matcha Project
 *  krambono - mhotting
 *  2019
********************************************************************************/

const db = require('./../util/database');
const bcrypt = require('bcrypt');
const faker = require('faker');
const cryptoRS = require('crypto-random-string');
faker.locale = 'fr';

/****************************************/
/*  USEFUL FUNCTIONS                    */
/****************************************/
// Clean an username by removing none alphanumeric chars
const cleanUsername = (username) => {
    const regex = /^[a-zA-Z0-9]$/;
    let newUsername = '';
    for (let char of username) {
        if (regex.test(char))
            newUsername += char;
    }
    return newUsername;
}

// Remove french accents from a string
const removeAccent = string => {
    const accent = [
        /[\300-\306]/g, /[\340-\346]/g, // A, a
        /[\310-\313]/g, /[\350-\353]/g, // E, e
        /[\314-\317]/g, /[\354-\357]/g, // I, i
        /[\322-\330]/g, /[\362-\370]/g, // O, o
        /[\331-\334]/g, /[\371-\374]/g, // U, u
        /[\321]/g, /[\361]/g, // N, n
        /[\307]/g, /[\347]/g, // C, c
    ];
    const noaccent = ['A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'N', 'n', 'C', 'c'];

    for (let i = 0; i < accent.length; i++) {
        string = string.replace(accent[i], noaccent[i]);
    }
    return string;
}

// Check if a given char is alphanumeric
const isLetter = c => {
    const regex = /^[a-zA-Z0-9]$/;
    return regex.test(c);
}

// Clean a string by removing the accents, trimming it, etc.
const cleanString = string => {
    const array = [];
    let newString = removeAccent(string);
    for (let char of newString) {
        if (isLetter(char))
            array.push(char);
    }
    newString = array.join('');
    return newString;
}

// Create user interests
const createInterests = () => {
    let interests = [];
    let interest;
    let promiseArray = [];
    let i = 0;

    while (i < 40) {
        interest = cleanUsername(cleanString(faker.random.word()));
        interest = interest.toLocaleLowerCase();
        if (interest.length >= 3 && (interests.indexOf(interest) === -1)) {
            interests.push(interest);
            i++;
        }
    }
    for (interest of interests) {
        promiseArray.push(db.execute(
            'INSERT INTO `db_matcha`.`t_interest` (`interest_name`) ' +
            'VALUES (?);',
            [interest]
        ));
    }
    return (promiseArray);
}

/****************************************/
/*  FAKE PROFILE GENERATOR              */
/****************************************/
const userTab = [];
const promiseArray = [];
const unameArray = [];
let interestPromiseArray = [];
const userObj = {};
const password = bcrypt.hashSync('Qwerty123', 12);
let rdmNbr;
let i;

interestPromiseArray = createInterests();
console.log('Generating fake interests...');
Promise.all(interestPromiseArray)
    .then(() => {
        console.log('OK');
        console.log('Generating fake users...');
        for (let i = 0; i < 500; i++) {
            do {
                userObj.usr_uname = cleanUsername(faker.internet.userName());
            } while (unameArray.indexOf(userObj.usr_uname) !== -1);
            unameArray.push(userObj.usr_uname);
            userObj.usr_fname = faker.name.firstName();
            userObj.usr_lname = faker.name.lastName();
            userObj.usr_email = faker.internet.email();
            userObj.usr_pwd = password;
            userObj.avatar1 = faker.internet.avatar();
            userObj.avatar2 = faker.internet.avatar();
            age = 0;
            while (age < 18 || age > 65) {
                age = faker.random.number();
            }
            userObj.usr_age = age;
            rdmNbr = Math.random();
            userObj.usr_gender = (rdmNbr < 0.5 ? 'male' : 'female');
            userObj.usr_bio = faker.lorem.paragraph();
            userObj.usr_status = "OK";

            // Longitude and latitude
            do {
                userObj.usr_longitude = faker.address.longitude();
            } while (userObj.usr_longitude < 4.0 || userObj.usr_longitude > 5.0);
            do {
                userObj.usr_latitude = faker.address.latitude();
            } while (userObj.usr_latitude < 45.00 || userObj.usr_latitude > 46.50);

            // Tokens
            userObj.usr_activationToken = cryptoRS(64);
            userObj.usr_pwdToken = cryptoRS(64);
            rdmNbr = Math.random();

            // Score, gender and orientation
            userObj.usr_score = Math.round(Math.random() * 500);
            userObj.usr_orientation = (rdmNbr < 0.66 ? (rdmNbr < 0.5 ? 'bi' : 'homo') : 'hetero');

            userTab.push({ ...userObj });
        }

        for (let user of userTab) {
            promiseArray.push(db.execute(
                'INSERT INTO `db_matcha`.`t_user` (`usr_uname`, `usr_fname`, `usr_lname`, `usr_email`, `usr_pwd`, `usr_age`, `usr_gender`, `usr_bio`, `usr_activationToken`, `usr_resetToken`, `usr_orientation`, `usr_longitude`, `usr_latitude`, `usr_score`, `usr_active`, `usr_loctype`) ' +
                'VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, 1, \'geo\');',
                [
                    user.usr_uname, user.usr_fname, user.usr_lname,
                    user.usr_email, user.usr_pwd, user.usr_age,
                    user.usr_gender, user.usr_bio, user.usr_activationToken,
                    user.usr_pwdToken, user.usr_orientation,
                    user.usr_longitude, user.usr_latitude, user.usr_score
                ]
            ));
        }
        return (Promise.all(promiseArray));
    })
    .then(result => {
        let i = 1;
        for (let user of userTab) {
            promiseArray.push(db.execute(
                'INSERT INTO t_image(image_path, image_idUser) ' +
                'VALUES ' +
                '(?, ?), (?, ?);',
                [user.avatar1, i, user.avatar2, i]
            ));
            i++;
        }
        return (Promise.all(promiseArray));
    })
    .then(result => {
        console.log('OK');
        console.log('Generating fake userInterests...');
        let tempNum;
        const userInterestPromiseArray = [];
        let num;
        let nb_interests;

        // Adding interests for each user
        for (let i = 1; i <= 500; i++) {
            tempNum = [];
            // Generating a random number of interest
            nb_interests = Math.round(Math.random() * 3);
            for (let j = 0; j < nb_interests; j++) {
                // Generating random interests IDs
                do {
                    num = Math.round(Math.random() * 39) + 1;
                } while (tempNum.indexOf(num) !== -1)
                tempNum.push(num);
            }

            // Adding userInterests in the DB
            for (let idInterest of tempNum) {
                userInterestPromiseArray.push(db.execute(
                    'INSERT INTO `db_matcha`.`t_userInterest` (`userInterest_idUser`, `userInterest_idInterest`) ' +
                    'VALUES (?, ?);',
                    [i, idInterest]
                ));
            }
        }
        return (Promise.all(userInterestPromiseArray));
    })
    .then(result => {
        console.log('SUCCESS - Fake data have been generated.');
    })
    .catch(error => {
        console.log(error);
    })
    .finally(result => {
        process.exit();
    });
