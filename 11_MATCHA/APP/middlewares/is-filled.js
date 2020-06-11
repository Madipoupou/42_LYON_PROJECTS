const User = require('../models/user');
const throwError = require('../util/error');

module.exports = (req, res, next) => {
    const userId = req.userId;

    User.findById(userId)
    .then(user => {
        if (!user.usr_gender || !user.usr_orientation)
            throwError('Vous devez renseigner votre genre et votre orientation pour accéder à la recherche', 400);
        next();
    })
    .catch(err => next(err));
};
