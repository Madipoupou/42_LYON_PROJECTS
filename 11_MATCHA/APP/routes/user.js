// Management of the users routes

const express = require('express');
const userController = require('../controllers/user.js');
const router = express.Router();
const isAuth = require('../middlewares/is-auth');
const isFilled = require('../middlewares/is-filled');

// GET - '/user'
router.get('/user', isAuth, userController.getInfos);

// GET - '/otherInfo'
router.get('/otherInfo/:uname', isAuth, userController.getOtherInfo);

// GET - '/userCompatible'
router.get('/userCompatible', isAuth, isFilled, userController.getInfosCompatible);

// GET - '/userMatch'
router.get('/userMatch', isAuth, isFilled, userController.getInfosMatch);


module.exports = router;