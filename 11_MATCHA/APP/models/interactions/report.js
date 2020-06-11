// Model of the reports

const db = require('./../../util/database');
const throwError = require('./../../util/error');

class Report {
    // Retrieve a report ID using the users IDs
    static findById(idReporter, idReported) {
        return (
            db.execute('SELECT report_id FROM t_report WHERE report_idReporter = ? AND report_idReported = ?;', [idReporter, idReported])
                .then(([rows, fields]) => rows[0])
        );
    }

    // Add a "report" when an user wants to report another one's account - Throws an error if the user to report is already reported
    static addReport(idReporter, idReported) {
        return (Report.findById(idReporter, idReported)
            .then(result => {
                if (result) {
                    throwError('Already Reported', 422);
                }
                return (db.execute('INSERT INTO t_report(report_idReporter, report_idReported) VALUES (?, ?);', [idReporter, idReported]));
            })
        );
    }

    // Count the report from an user
    static countReport(idReported) {
        return (db.execute('SELECT COUNT(*) AS `nb` FROM t_report WHERE report_idReported = ?;', [idReported])
            .then(([rows, fields]) => rows[0])
        );
    }

    // Delete a "report" when an user wants to unreport another one's account - Throws an error if the user to unreport isn't reported
    static deleteReport(idReporter, idReported) {
        return (Report.findById(idReporter, idReported)
            .then(result => {
                if (!result) {
                    throwError('Already Unreported', 422);
                }
                return (db.execute('DELETE FROM t_report WHERE report_idReporter = ? AND report_idReported = ?;', [idReporter, idReported]));
            })
        );
    }
}


module.exports = Report;