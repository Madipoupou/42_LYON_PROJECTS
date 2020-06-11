/*
    Create and manage the nodeJS server
    Matcha project
    krambono - mhotting
    2019
*/

// Importing third party packages
const express = require('express');
const bodyParser = require('body-parser');
const path = require('path');
const rootDir = require('./util/rootDir');

// Importing routes and controllers
const authRoutes = require('./routes/auth');
const messagesRoutes = require('./routes/messages');
const interactionsRoutes = require('./routes/interactions');
const notificationsRoutes = require('./routes/notifications');
const userRoutes = require('./routes/user');
const imagesRoutes = require('./routes/images');

// Creating the app
const app = express();

// Authorize access to public folder
app.use(express.static(path.join(rootDir, 'public')));

// Setting headers to allow data exchange between clients and server
app.use((req, res, next) => {
    res.setHeader('Access-Control-Allow-Origin', '*');
    res.setHeader('Access-Control-Allow-Methods', 'OPTIONS, GET, POST, PATCH, PUT, DELETE');
    res.setHeader('Access-Control-Allow-Headers', 'Content-Type, Authorization');
    next();
});

// Parsing incoming request body
app.use(bodyParser.json({
    limit: '26000kb'  
}));

app.use((error, req, res, next) => {
    console.log('ERREUR CATCH');
    console.log(error);
    console.log('----------------------');
    let message;
    switch(error.type){
        case 'entity.too.large':
            message = 'Taille de fichier trop grande';
            break;
        case 'entity.parse.failed':
            message = 'JSON envoyé mal formaté';
            break;
        default:
            message = 'Une erreur est survenue durant le parsing de la requete';
    }
    res.status(422).json({message});
});

// Using imported routes
app.use('/auth', authRoutes);
app.use(messagesRoutes);
app.use('/interact', interactionsRoutes);
app.use('/notifications', notificationsRoutes);
app.use(userRoutes);
app.use('/images', imagesRoutes);

// Unexisting pages management
app.use((req, res, next) => {
    res.status(404).json({
        message: 'Page not found'
    });
});

// Catching errors
app.use((error, req, res, next) => {
    console.log('ERREUR CATCH');
    console.log(error);
    console.log('----------------------');
    const status = !error.statusCode ? 500 : error.statusCode;
    const message = error.message;
    res.status(status).json({
        //message: status === 500 ? 'Server Error' : message
        message: message
    });
});

// Making the server listen
const server = app.listen(8080, '0.0.0.0');
require('./util/socket').init(server);
