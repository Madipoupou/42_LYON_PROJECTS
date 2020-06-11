// Model of the users' interests
//(connection between an user and its interests)

const db = require('../util/database');

class UserInterest {
    // Checks is a given user is linked to a given interest (both given by IDs)
    static exist(userId, interestId) {
        return db.execute(
            'SELECT * FROM t_userInterest ' +
            'WHERE userInterest_idUser=? AND userInterest_idInterest=?',
            [userId, interestId]
        )
            .then(([rows, field]) => !!rows[0]);
    }

    // Register an user's interest (according to IDs)
    static add(userId, interestId) {
        return UserInterest.exist(userId, interestId)
            .then(test => {
                if (test === false) {
                    return db.execute(
                        'INSERT INTO t_userInterest ' +
                        '(userInterest_idUser, userInterest_idInterest) ' +
                        'VALUES (?, ?)',
                        [userId, interestId]
                    );
                }
            });
    }

    // Delete all the interests from an user, according to its id
    static removeAll(userId) {
        return (db.execute(
            'DELETE FROM t_userInterest ' +
            'WHERE userInterest_idUser = ?;',
            [userId]
        ));
    }

    // Get the number of interests that two users have in common
    static getCommonInterests(userId, otherId) {
        return(db.execute(
            'SELECT COUNT(*) AS `tot` FROM (' +
            'SELECT COUNT(*) AS `nb`, userInterest_idInterest FROM t_userInterest ' +
            'WHERE (userInterest_idUser = ? OR userInterest_idUser = ?) ' +
            'GROUP BY(userInterest_idInterest)' +
            ') AS SUB_TABLE ' +
            'WHERE nb = 2;', [userId, otherId])
            .then(([rows, fields]) => rows[0])
        );
    }
}

module.exports = UserInterest;
