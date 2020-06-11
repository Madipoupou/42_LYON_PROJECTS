// Route for managing images

const express = require('express');
const imagesController = require('../controllers/images');

const isAuth = require('../middlewares/is-auth'); 
const validation = require('../middlewares/validation');

const router = express.Router();

// PUT '/images/save' -> saving images from json request to files on the server
router.put('/save', isAuth, validation.userImage, imagesController.userImage);

// DELETE '/images/delete' -> delete images according to array of IDs
router.delete('/delete', isAuth, validation.deleteImage, imagesController.delete);

module.exports = router;