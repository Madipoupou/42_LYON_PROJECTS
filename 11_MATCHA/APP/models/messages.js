// Model of the messages

const db = require('../util/database');
const Notification = require('./notifications');
const User = require('./user');
const Match = require('./interactions/match');
const throwError = require('../util/error');

class Message {
    // Constructor of a message
    constructor(content, idSender, idReceiver) {
        this.content = content;
        this.idSender = idSender;
        this.idReceiver = idReceiver;
    }

    // Insert a message into the database
    create() {
        return Match.findById(this.idSender, this.idReceiver)
        .then(match => {
            if (!match)
                throwError('Vous n\'avez pas de match avec cette personne !', 400);
            return true;
        })
        .then(() => {
            return db.execute(
                'INSERT INTO t_message (msg_content, msg_idSender, msg_idReceiver) VALUES(?, ?, ?)',
                [this.content, this.idSender, this.idReceiver]
            );      
        })
        .then(result => {
            return (Notification.addNotification(this.idReceiver, this.idSender, 'Message'));
        });
    }

    // Retrieve the conversations available for a given user according to its id
    // A conversation between two users is available when they match
    static getConvs(userId) {
        let matchs;
        return db.execute(
            'SELECT match_id1, match_id2, match_date AS date ' +
            'FROM t_match ' +
            'WHERE match_id1=? OR match_id2=?',
            [userId, userId]
        )
        .then(([rows, fields]) => {
            matchs = rows.map(row => {
                return {
                    userId: row.match_id1 === userId ? row.match_id2 : row.match_id1,
                    date: row.date
                }
            });
        })
        .then(() => {
            const promises = matchs.map(match => {
                return User.findById(match.userId).then(user => {
                    match.uname = user.usr_uname;
                });
            });
            return Promise.all(promises);
        })
        .then(() => {
            const promises = matchs.map(match => {
                return Message.getAll(match.userId, userId).then(messages => {
                    match.nbMsgs = messages.length;
                });
            });
            return Promise.all(promises);
        })
        .then(() => {
            const promises = matchs.map(match => {
                if (match.nbMsgs <= 0)
                    return true;
                return db.execute(
                    'SELECT MAX(msg_creationDate) AS date ' + 
                    'FROM t_message ' +
                    'WHERE (msg_idSender=? AND msg_idReceiver=?) OR (msg_idSender=? AND msg_idReceiver=?)',
                    [match.userId, userId, userId, match.userId]
                )
                .then(([rows, fields]) => rows[0])
                .then(res => {
                    match.date = res.date;
                });
            });
            return Promise.all(promises);
        })
        .then(() => {
            matchs.sort((el1, el2) => {
                const timestamp1 = new Date(el1.date).getTime();
                const timestamp2 = new Date(el2.date).getTime();
                if (timestamp1 > timestamp2)
                    return -1;
                if (timestamp1 === timestamp2)
                    return 0;
                if (timestamp1 < timestamp2)
                    return 1;
            });
        })
        .then(() => {
            for (let match of matchs) {
                const initialDate = new Date(match.date);
                //console.log('heures:', initialDate.getHours());
                const formatNumber = nb => ("0" + +nb).slice(-2);
                match.date = formatNumber(initialDate.getDate()) + ' ' + formatNumber((initialDate.getMonth() + 1)) + ' ' +
                initialDate.getFullYear() + ' - ' + initialDate.getHours() + ':' + String(initialDate.getMinutes()).padStart(2, "0");
                //console.log('date:', match.date);
            }
            return matchs;
        })
    }

    // Retrive all the messages from a conversation between two users according to their IDs
    static getAll(userId, scdUserId) {
        return Match.findById(userId, scdUserId)
        .then(match => {
            if (!match)
                throwError('Vous n\'avez pas de match avec cette personne !', 400);
            return true;
        })
        .then(() => {
            return db.execute(
                'SELECT msg_content AS content, DATE_FORMAT(msg_creationDate, "%d/%c/%y %H:%i") AS date, usr_uname AS uname ' +
                'FROM t_message ' +
                'JOIN t_user ' +
                'ON msg_idSender=usr_id ' +
                'WHERE (msg_idSender=? AND msg_idReceiver=?) OR (msg_idSender=? AND msg_idReceiver=?) ' +
                'ORDER BY msg_creationDate',
                [userId, scdUserId, scdUserId, userId]
            );
        })
        .then(([rows, field]) => rows);
    }
}

module.exports = Message;
