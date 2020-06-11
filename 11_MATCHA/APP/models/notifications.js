// Model of the interests

const db = require('./../util/database');
const throwError = require('./../util/error');
const io = require('../util/socket');
const User = require('./user');

class Notification {
    // Retrieve a notif according to its id
    static findById(idNotif) {
        return (
            db.execute('SELECT * FROM t_notification WHERE notif_id = ?;', [idNotif])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Add a notification to DB according to the id of the user it belongs and the category of the notification
    static addNotification(idUser, idOther, category) {
        let message;
        let oldNotif;
        let uname;

        Notification.getUnread(idUser, idOther, category)
            .then(notif => {
                if (notif) {
                    oldNotif = notif;
                    return(
                        db.execute('UPDATE t_notification SET notif_creationDate = NOW() WHERE notif_id = ?;', [notif.notif_id])
                            .then(result => {
                                return(User.findById(idUser));
                            })
                            .then(user => {
                                io.emitEventTo(user.usr_uname, 'notif', {
                                    type: category,
                                    content: oldNotif.notif_message,
                                    userId: +idOther
                                });
                            })
                    );
                }
                return (
                    User.findById(idOther)
                        .then(user => {
                            uname = user.usr_uname;
                            switch (category) {
                                case 'Match':
                                    message = 'Nouveau match avec ' + uname;
                                    break;
                                case 'Unmatch':
                                    message = 'Le match avec ' + uname + ' a disparu';
                                    break;
                                case 'Like':
                                    message = uname + ' aime votre profil';
                                    break;
                                case 'Visit':
                                    message = uname + ' a visité votre profil';
                                    break;
                                case 'Message':
                                    message = uname + ' vous a envoyé un message';
                                    break;
                            }
                            return(db.execute(
                                'INSERT INTO t_notification(notif_idUser, notif_idOther, notif_consulted, notif_category, notif_message) ' +
                                'VALUES (?, ?, 0, ?, ?);',
                                [idUser, idOther, category, message]
                            ));
                        })
                        .then(result => {
                            return(User.findById(idUser));
                        })
                        .then(user => {
                            io.emitEventTo(user.usr_uname, 'notif', {
                                type: category,
                                content: message,
                                userId: +idOther
                            });
                        })
                );
            })
    }

    // Set a notification as read or unread depending on the state arg (0: set as unread / 1: set as read)
    // If the notification does not exist, an error is thrown
    static setReadNotification(idUser, idNotif, state) {
        if (!idNotif || state === undefined || (state != 0 && state != 1)) {
            throwError('idNotif et state (0 ou 1) attendus', 422);
        }
        return (this.findById(idNotif)
            .then(result => {
                if (!result) {
                    throwError('Notification inexistante', 422);
                }
                if (result.notif_idUser !== idUser) {
                    throwError('Notification d\'un autre utilisateur', 422);
                }
                if (state == 0) {
                    return (db.execute('UPDATE t_notification SET notif_consulted = 0 WHERE notif_id = ?;', [idNotif]));
                } else {
                    return (db.execute('UPDATE t_notification SET notif_consulted = 1 WHERE notif_id = ?;', [idNotif]));
                }
            })
        );
    }

    // Delete a notification
    // If the notification does not exist, an error is thrown
    static deleteNotification(idUser, idNotif) {
        if (!idNotif)
            throwError('idNotif attendu', 400);
        return (this.findById(idNotif)
            .then(result => {
                if (!result)
                    throwError('Notification inexistante', 400);
                if (result.notif_idUser !== idUser)
                    throwError('Notification d\'un autre utilisateur', 400);
                return (db.execute('DELETE FROM t_notification WHERE notif_id = ?;', [idNotif]));
            })
        );
    }

    // Delete all the notification from an user
    static deleteAllNotifications(idUser) {
        return (db.execute('DELETE FROM t_notification WHERE notif_idUser = ?;', [idUser]));
    }

    // Set all the notifications as read for a given user
    static setAllReadNotification(idUser) {
        return (db.execute(
            'UPDATE t_notification ' +
            'SET notif_consulted = 1 ' +
            'WHERE notif_idUser = ?;',
            [idUser]
        ));
    }

    // Retrieve all the notifications from a given user
    static getAll(userId) {
        return (db.execute(
            'SELECT *, ' + 
            'DATE_FORMAT(notif_creationDate, "%d/%c/%y %H:%i") AS date ' +
            'FROM t_notification ' +
            'WHERE notif_idUser = ? ' +
            'ORDER BY notif_creationDate DESC;',
            [userId]
        ));
    }

    // Retrieve the last five notifs from a given user
    static getLast(userId) {
        return (
            db.execute(
                'SELECT * ' +
                'FROM t_notification ' +
                'WHERE notif_idUser = ? ' +
                'ORDER BY notif_creationDate DESC ' +
                'LIMIT 5;',
                [userId]
            ).then(([rows, fields]) => rows)
        );
    }

    // Count all the unchecked notifications from a given user
    static countByUser(userId) {
        return (
            db.execute(
                'SELECT COUNT(*) AS \'nb\' FROM t_notification ' +
                'WHERE notif_idUser = ? AND notif_consulted = 0;',
                [userId]
            ).then(([rows, fields]) => rows[0])
        );
    }

    // Get a notification if it is unread according to userId, otherId and category
    static getUnread(idUser, idOther, category) {
        return (
            db.execute(
                'SELECT notif_id, notif_message FROM t_notification ' +
                'WHERE notif_idUser = ? AND notif_idOther = ? AND notif_category = ? AND notif_consulted = 0;',
                [idUser, idOther, category]
            ).then(([rows, fields]) => rows[0])
        );
    }
}


module.exports = Notification;