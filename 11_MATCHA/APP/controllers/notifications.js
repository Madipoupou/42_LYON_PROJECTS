// Controller of the notifications

const throwError = require('../util/error');
const Notifications = require('../models/notifications');
const User = require('../models/user');

// Retrieve all the notifications of an user
exports.getNotifications = (req, res, next) => {
    const userId = req.userId;
    Notifications.getAll(userId)
        .then(([rows, fields]) => rows)
        .then(rows => {
            const notifications =  rows.map(row => {
                return {
                    id: row.notif_id,
                    date: row.date,
                    seen: !!row.notif_consulted,
                    type: row.notif_category,
                    content: row.notif_message,
                    otherUserId: row.notif_idOther
                }
            });
            return notifications;
        })
        .then(notifs => {
            const promises = notifs.map(notif => {
                return User.findById(notif.otherUserId).then(user => {
                    notif.otherUsername = user.usr_uname;
                });
            });
            return Promise.all(promises).then(_ => notifs);
        })
        .then(notifs => {
            for (notif of notifs) {
                let link = '';
                switch(notif.type){
                    case 'Match': 
                    case 'Message': 
                        link = '/chat/' + notif.otherUsername; break;
                    case 'Visit': 
                    case 'Like':
                    case 'Unmatch': 
                        link = '/user/' + notif.otherUsername; break;
                }
                notif.link = link;
            }
            return notifs;
        })
        .then(notifications => res.status(200).json({notifications}))
        .catch(error => next(error));
};

// Count the notifications from a given user
exports.getCountNotifications = (req, res, next) => {
    const userId = req.userId;
    Notifications.countByUser(userId)
        .then(row => {
            res.status(200).json({
                count: row['nb']
            });
        })
        .catch(error => next(error));
}

// Set a given notification as read/unread, according to its id
// Id is checked in notification model
// Need to receive a state property (0 or 1) to set as read (1) or unread (0)
exports.putReadOne = (req, res, next) => {
    const userId = req.userId;
    const idNotif = req.body.idNotif;
    const state = req.body.state;

    Notifications.setReadNotification(userId, idNotif, state)
        .then(row => {
            res.status(200).json({
                message: 'Notification mise à jour'
            });
        })
        .catch(error => next(error));
}

// Delete a given notification according to its id
exports.deleteOne = (req, res, next) => {
    const userId = req.userId;
    const idNotif = req.body.idNotif;

    Notifications.deleteNotification(userId, idNotif)
        .then(_ => {
            res.status(200).json({
                message: 'Notification supprimée'
            });
        })
        .catch(error => next(error));
}

// Delete all the notifications from an user
exports.deleteAll = (req, res, next) => {
    const userId = req.userId;

    Notifications.deleteAllNotifications(userId)
        .then(_ => {
            res.status(200).json({
                message: 'Notifications supprimées'
            });
        })
        .catch(error => next(error));
}

// Set all the notifications from an user as read
exports.putReadAll = (req, res, next) => {
    const userId = req.userId;

    Notifications.setAllReadNotification(userId)
        .then(row => {
            res.status(200).json({
                message: 'Notifications lues'
            });
        })
        .catch(error => next(error));
}
