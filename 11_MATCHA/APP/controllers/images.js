// Controller of all the images stuff

const throwError = require('../util/error');
const fs = require('fs');
const Images = require('./../models/images');
const Magic = require('promise-mmmagic');
const util = require('util');
const md5 = require('md5');
const fs_writeFile = util.promisify(fs.writeFile);
const fs_unlink = util.promisify(fs.unlink);

const uniqid = () => {
    return md5((new Date().getTime() + Math.floor((Math.random()*10000)+1)).toString(16));
};

// Save images into the database and the server
exports.userImage = (req, res, next) => {
    let images = req.images;
    let imageName;
    let finalImage;
    let imageArray = [];
    const uname = req.username;
    const userId = req.userId;
    let promiseArray = [];
    let imageCount;

    Images.count(req.userId)
        .then(row => {
            imageCount = row.nb;
            // Checking all the images and preparing an array to store them if they are all ok
            for (let i = 0; i < images.length; i++) {
                // Setting the image name and cleaning the base64 string - then pushing it into the array
                const regex = /^data:image\/((jpeg)|(jpg)|(gif)|(png));base64,/;
                finalImage = images[i].replace(regex, '');

                // Creating a buffer and using mmmMagic to check it
                const buff = Buffer.from(finalImage, 'base64');
                const magic = new Magic(Magic.MAGIC_MIME_TYPE);
                promiseArray.push(magic.detect(buff)
                    .then(result => {
                        let type = result.split('/')[1];
                        if (type !== 'png' && type !== 'jpeg' && type !== 'jpg' && type !== 'gif') {
                            throwError('Formats supportés: png, jpeg, jpg, gif', 422);
                        }
                        imageName = uniqid() + '.' + type;
                        imageArray.push({ name: imageName, buff: buff });
                    }));
            }
            return (Promise.all(promiseArray));
        })
        .then(_ => {
            promiseArray = imageArray.map(image => Images.create(userId, 'http://localhost:8080/images/' + image.name));
            return (Promise.all(promiseArray));
        })
        .then(_ => {
            promiseArray = imageArray.map(image => fs_writeFile('./public/images/' + image.name, image.buff));
            return (Promise.all(promiseArray));
        })
        .then(_ => {
            res.status(201).json({
                message: 'Images sauvegardées'
            });
        }) 
        .catch(error => next(error));
}

// Delete an image from the database and the server according to its id
exports.delete = (req, res, next) => {
    const images = req.body.images;
    let fileArray = [];
    let promiseArray;

    const regex = /^http:\/\/localhost:8080\/images\//;
    const regex2 = /^https:/;
    promiseArray = images.map(image => Images.findById(image)
        .then(img => {
            fileArray.push(img.image_path.replace(regex, ''));
        })
    );
    Promise.all(promiseArray)
        .then(_ => {
            promiseArray = images.map(image => Images.delete(image));
            return (Promise.all(promiseArray));
        })
        .then(_ => {
            promiseArray = fileArray.map(file => {
                if (!regex2.test(file))
                    return (fs_unlink('./public/images/' + file));
                else
                    return (true);
            });
            return (Promise.all(promiseArray));
        })
        .then(_ => {
            res.status(201).json({
                message: 'Image supprimée'
            });
        })
        .catch(err => next(err));
}