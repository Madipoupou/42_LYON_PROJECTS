// Middleware that enable to check if a user is authentified
// We use the JWT (Json Web Token principle)
// The token sent is unique and available for one hour when created

// IMPORTANT -> In the request, a header need to be set: Authorization : 'Bearer ' + token

const jwt = require('jsonwebtoken');
const throwError = require('../util/error');

module.exports = (req, res, next) => {
    const authHeader = req.get('Authorization');
    if (!authHeader)
        throwError('Vous devez vous connecter pour accéder à cette page', 401);
    const token = authHeader.split(' ')[1];
    const decodedToken = jwt.verify(token, ';R)LK4nh=]POwYtcJy=u5aEEI');
    if (!decodedToken)
        throwError('Vous devez vous connecter pour accéder à cette page', 401);
    req.userId = decodedToken.userId;
    req.username = decodedToken.username;
    next();
};
