// Management of the messages routes

const express = require('express');
const msgController = require('../controllers/messages');

const isAuth = require('../middlewares/is-auth');

const router = express.Router();

// GET - '/chat'
router.get('/chat', isAuth, msgController.getConvs);

// GET - '/chat/username'
router.get('/chat/:uname', isAuth, msgController.getMessagesUser);

// POST - '/chat/username'
router.post('/chat/:uname', isAuth, msgController.postMessage);

module.exports = router;
