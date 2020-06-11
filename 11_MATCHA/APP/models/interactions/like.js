// Model of the interactions

const db = require('./../../util/database');
const throwError = require('./../../util/error');
const Match = require('./match');
const Notification = require('./../notifications');
const User = require('./../user');
const Images = require('./../images');

class Like {
    // Retrieve a like ID using the users IDs
    static findById(idLiker, idLiked) {
        return (
            db.execute('SELECT like_id FROM t_like WHERE like_idLiker = ? AND like_idLiked = ?;', [idLiker, idLiked])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Add a "like" when an user wants to like another one - Throws an error if the user is already liked
    // If the liker is already liked by the other person, a match is added
    // When an user is liked, a notification is registered in the DB
    // When there is a match, a notification is registered for both users in the DB
    
    static addLike(idLiker, idLiked) {
        return (Images.count(idLiker)
            .then(row => {
                if (row.nb === 0) {
                    throwError('Pour liker, vous devez ajouter au moins une photo de profil', 422);
                }
                return (Like.findById(idLiker, idLiked));
            })
            .then(result => {
                if (result) {
                    throwError('Already Liked', 422);
                }
                return (db.execute('INSERT INTO t_like(like_idLiker, like_idLiked) VALUES (?, ?);', [idLiker, idLiked]));
            })
            .then(result => {
                return (User.upScore(idLiker, idLiked, 5));
            })
            .then(result => {
                return (Notification.addNotification(idLiked, idLiker, 'Like'));
            })
            .then(result => {
                return (Match.findById(idLiker, idLiked));
            })
            .then(result => {
                if (result) {
                    return (Promise.resolve('Already Matched'));
                }
                return (
                    Like.findById(idLiked, idLiker)
                        .then(result => {
                            if (!result) {
                                return (Promise.resolve('No Match Yet'));
                            }
                            return (Match.addMatch(idLiker, idLiked));
                        })
                );
            })
        );
    }

    // Delete a "like" when an user wants to unlike another one - Throws an error if the user to like is not liked
    // If there was a match between the users, the match is removed
    static deleteLike(idLiker, idLiked) {
        return (Images.count(idLiker)
            .then(row => {
                if (row.nb === 0) {
                    throwError('Pour ne plus liker, vous devez ajouter au moins une photo de profil', 422);
                }
                return (Like.findById(idLiker, idLiked));
            })
            .then(result => {
                if (!result) {
                    throwError('Already Unliked', 422);
                }
                return (db.execute('DELETE FROM t_like WHERE like_idLiker = ? AND like_idLiked = ?;', [idLiker, idLiked]));
            })
            .then(result => {
                return (User.downScore(idLiker, idLiked, 5));
            })
            .then(result => {
                return (Match.findById(idLiker, idLiked));
            })
            .then(result => {
                if (!result) {
                    return (Promise.resolve('No Match'));
                }
                return (Match.deleteMatch(idLiker, idLiked));
            })
        );
    }

    // Get all the users who liked a given user
    static getLikes(userId) {
        return db.execute (
            'SELECT like_idLiker AS other_id, DATE_FORMAT(like_date, "%d/%m/%y") AS date ' +
            'FROM t_like ' +
            'WHERE like_idLiked = ? ' +
            'ORDER BY like_date',
            [userId]
        )
        .then(([rows, fields]) => rows);
    }
}


module.exports = Like;