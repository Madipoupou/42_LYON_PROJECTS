// Management of the notifications routes

const express = require('express');

const isAuth = require('../middlewares/is-auth');

const notifController = require('./../controllers/notifications.js');

const router = express.Router();

// GET - '/notifications/all'
router.get('/all', isAuth, notifController.getNotifications);

// GET - '/notifications/count'
router.get('/count', isAuth, notifController.getCountNotifications);

// PUT - '/notifications/readOne'
router.put('/readOne', isAuth, notifController.putReadOne);

// DELETE - '/notifications/delete'
router.delete('/delete', isAuth, notifController.deleteOne);

// DELETE - '/notifications/deleteAll'
router.delete('/deleteAll', isAuth, notifController.deleteAll);

// PUT - '/notifications/readAll'
router.put('/readAll', isAuth, notifController.putReadAll);


module.exports = router;
