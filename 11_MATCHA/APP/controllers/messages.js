// Controller of the messages

const throwError = require('../util/error');
const User = require('../models/user');
const Message = require('../models/messages');
const io = require('../util/socket');

// Retrieve all the conversations for a given user
// Conversations are available only for matching people
exports.getConvs = (req, res, next) => {
    Message.getConvs(req.userId)
        .then(matchs => {
            res.status(200).json(matchs);
        })
        .catch(err => next(err));
}

// Retrieve the conversaiton between two users
exports.getMessagesUser = (req, res, next) => {
    const username = req.params.uname;

    User.findByUsername(username)
        .then(sndUser => {
            if (!sndUser)
                throwError('Utilisateur inexistant', 400);
            return Message.getAll(req.userId, sndUser.usr_id);
        })
        .then(messages => {
            res.status(200).json({
                messages: messages
            });
        })
        .catch(err => next(err));
};


// Store a message in the DB
exports.postMessage = (req, res, next) => {
    const username = req.params.uname;
    const content = req.body.content;

    if (!content || typeof content !== 'string')
        throwError('Message invalide', 422);
    User.findByUsername(username)
        .then(sndUser => {
            if (!sndUser)
                throwError('Utilisateur inexistant', 400);
            const message = new Message(content, req.userId, sndUser.usr_id);
            return message.create();
        })
        .then(() => {
            io.emitEventTo(username, 'msg', {
                username: req.username,
                content: req.body.content,
                whoami: 'receiver'
            });
            io.emitEventTo(req.username, 'msg', {
                username: username,
                content: req.body.content,
                whoami: 'sender'
            });
        })
        .then(() => {
            res.status(201).json({
                message: 'Le message a bien été créé'
            });
        })
        .catch(err => next(err));
};
