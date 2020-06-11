// Model of the interests

const db = require('../util/database');
const cleanString = require('../util/accent');

class Interest {
    // Retrieve the id of an interest according to its name
    static getId(interestName) {
        return db.execute(
            'SELECT interest_id FROM t_interest ' +
            'WHERE interest_name=? ',
            [interestName]
        )
            .then(([rows, fields]) => rows[0] ? rows[0].interest_id : false);
    }

    // Retrieve the name of an interest according to its id
    static getName(interestId) {
        return db.execute(
            'SELECT interest_name FROM t_interest ' +
            'WHERE interest_id=? ',
            [interestId]
        )
            .then(([rows, fields]) => rows[0] ? rows[0].interest_name : false);
    }

    // Insert an interest to the database
    static neww(interestName) {
        return db.execute(
            'INSERT INTO t_interest ' +
            '(interest_name) ' +
            'VALUES (?)',
            [interestName]
        );
    }

    // Clean an interest and add it to the DB (using new function above)
    static add(interestName) {
        interestName = cleanString(interestName);
        if (!interestName)
            return false;
        return Interest.getId(interestName)
            .then(interestId => {
                if (interestId !== false)
                    return interestId;
                else {
                    return Interest.neww(interestName)
                        .then(() => {
                            return Interest.getId(interestName);
                        });
                }
            });
    }

    // Get all the interests from one user
    static getInterestsFromUserId(userId) {
        return db.execute(
            'SELECT interest_name ' +
            'FROM t_userInterest ' +
            'JOIN t_interest ' +
            'ON t_userInterest.userInterest_idInterest = t_interest.interest_id ' +
            'WHERE userInterest_idUser=?',
            [userId]
        )
        .then(([rows, fields]) => rows);
    }
}

module.exports = Interest;
