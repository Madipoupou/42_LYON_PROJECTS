// Model of the interactions

const db = require('./../../util/database');
const throwError = require('./../../util/error');
const Notification = require('./../notifications');
const User = require('./../user');

class Visit {
    // Retrieve a visit ID using the id of the user visited
    static findById(idVisited) {
        return (
            db.execute('SELECT visit_id FROM t_visit WHERE visit_idVisited = ?;', [idVisited])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Count the number of visit for a given user
    static countVisit(userId) {
        return (
            db.execute('SELECT COUNT(*) AS `nb` FROM t_visit WHERE visit_idVisited = ?;', [userId])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Add a visit to a user in the DB
    // User visited is notified
    static addVisit(idVisitor, idVisited) {
        return (
            db.execute('SELECT MAX(visit_date) AS `date` FROM t_visit WHERE visit_idVisitor = ? AND visit_idVisited = ?;', [idVisitor, idVisited])
                .then(([rows, fields]) => rows[0])
                .then(row => {
                    if (!row) {
                        return true;
                    }
                    const now = new Date().getTime();
                    const date = new Date(row.date).getTime();
                    const diff = new Date(now - date).getHours();
                    return diff >= 6;
                })
                .then(test => {
                    if (test) {
                        return (db.execute('INSERT INTO t_visit(visit_idVisitor, visit_idVisited) VALUES (?, ?);', [idVisitor, idVisited])
                            .then(result => {
                                return (User.upScore(idVisitor, idVisited, 1));
                            })
                            .then(result => {
                                Notification.addNotification(idVisited, idVisitor, 'Visit');
                            })
                        )
                    }
                })      
        );
    }

    // Get all the visits of a given user grouping by visitor
    static getVisits(idVisited) {
        return (
            db.execute(
                'SELECT visit_idVisitor AS other_id, COUNT(visit_id) AS total, DATE_FORMAT(MAX(visit_date), "%d/%m/%y") AS date ' +
                'FROM t_visit ' +
                'WHERE visit_idVisited = ? ' +
                'GROUP BY visit_idVisitor ' +
                'ORDER BY total DESC',
                [idVisited]
            )
        )
        .then(([rows, fields]) => rows);
    }
}

module.exports = Visit;
