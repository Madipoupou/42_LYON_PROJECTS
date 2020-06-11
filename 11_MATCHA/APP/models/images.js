// Model of the images

const db = require('../util/database');

class Images {
    // Find an image according to its id
    static findById(imageId) {
        return (db.execute('SELECT * FROM t_image WHERE image_id = ?;', [imageId])
            .then(([rows, fields]) => rows[0])
        );
    }
    // Insert an image into the database
    static create(userId, name) {
        return (db.execute('INSERT INTO t_image(image_path, image_idUser) VALUES (?, ?);', [name, userId]));
    }

    // Delete all the images from an user
    static delete(imageId) {
        return (db.execute('DELETE FROM t_image WHERE image_id = ?;', [imageId]));
    }

    // Get all the images from an user
    static getAll(userId) {
        return (db.execute('SELECT * FROM t_image WHERE image_idUser = ?;', [userId])
            .then(([rows, fields]) => rows)
        );
    }

    // Count the images of an user
    static count(userId) {
        return (db.execute('SELECT COUNT(*) AS `nb` FROM t_image WHERE image_idUser = ?;' , [userId])
            .then(([rows, fields]) => rows[0])
        );
    }
}

module.exports = Images;
