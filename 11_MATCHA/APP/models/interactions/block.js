// Model of the interactions

const db = require('../../util/database');
const throwError = require('./../../util/error');
const Like = require('./like');

class Block {
    // Retrieve a block id according to users IDs
    static findById(idBlocker, idBlocked) {
        return (
            db.execute('SELECT block_id FROM t_block WHERE block_idBlocker = ? AND block_idBlocked = ?;', [idBlocker, idBlocked])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Find a block no matter id orders
    static findByIdNoOrder(id1, id2) {
        return (
            db.execute('SELECT block_id FROM t_block WHERE (block_idBlocker = ? AND block_idBlocked = ?) OR (block_idBlocker = ? AND block_idBlocked = ?);', [id1, id2, id2, id1])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Add a "block" when an user wants to block another one - Throws an error if the user to block is already blocked
    static addBlock(idBlocker, idBlocked) {
        return (Block.findById(idBlocker, idBlocked)
            .then(result => {
                if (result) {
                    throwError('Already Blocked', 422);
                }
                return (db.execute('INSERT INTO t_block(block_idBlocker, block_idBlocked) VALUES (?, ?);', [idBlocker, idBlocked]));
            })
            .then(_ => {
                return (Like.findById(idBlocker, idBlocked));
            })
            .then(result => {
                if (result) {
                    return (Like.deleteLike(idBlocker, idBlocked));
                }
            })
        );
    }

    // Delete a "block" when an user wants to unblock another one - Throws an error if the user to unblock isn't blocked
    static deleteBlock(idBlocker, idBlocked) {
        return (Block.findById(idBlocker, idBlocked)
            .then(result => {
                if (!result) {
                    throwError('Already Unblocked', 422);
                }
                return (db.execute('DELETE FROM t_block WHERE block_idBlocker = ? AND block_idBlocked = ?;', [idBlocker, idBlocked]));
            })
        );
    }

    // Get all the users blocked by an a given user
    static getBlocks(userId) {
        return db.execute (
            'SELECT block_idBlocked AS other_id, DATE_FORMAT(block_date, "%d/%m/%y") AS date ' +
            'FROM t_block ' +
            'WHERE block_idBlocker = ? ' +
            'ORDER BY block_date',
            [userId]
        )
        .then(([rows, fields]) => rows);
    }
}


module.exports = Block;