/********************************************************************************
 *  DATABASE creation - JS version
 *  Matcha Project
 *  krambono - mhotting
 *  2019
********************************************************************************/

const db = require('./../util/database');

/********************
* Delete DATABASE / Create DATABASE
********************/
db.execute(
    'DROP DATABASE IF EXISTS `db_matcha`;'
)
    .then(result => {
        return (db.execute(
            'CREATE SCHEMA `db_matcha` DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci; '
        ));
    })
    .then(result => {
        // T_USER table
        let promise1 = db.execute(
            'CREATE TABLE `db_matcha`.`t_user` (' +
            '`usr_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`usr_uname` VARCHAR(255) NOT NULL,' +
            '`usr_fname` VARCHAR(255) NOT NULL,' +
            '`usr_lname` VARCHAR(255) NOT NULL,' +
            '`usr_email` VARCHAR(255) NOT NULL,' +
            '`usr_pwd` VARCHAR(255) NOT NULL,' +
            '`usr_age` INT,' +
            '`usr_gender` VARCHAR(25),' +
            '`usr_bio` TEXT NULL,' +
            '`usr_score` INT DEFAULT 0,' +
            '`usr_active` TINYINT NOT NULL DEFAULT 0,' +
            '`usr_report` TINYINT NOT NULL DEFAULT 0,' +
            '`usr_loctype` VARCHAR(25),' +
            '`usr_longitude` FLOAT,' +
            '`usr_latitude` FLOAT,' +
            '`usr_creationDate` DATETIME DEFAULT NOW(),' +
            '`usr_connectionDate` DATETIME DEFAULT NOW(),' +
            '`usr_activationToken` VARCHAR(255),' +
            '`usr_resetToken` VARCHAR(255),' +
            '`usr_orientation` VARCHAR(45) DEFAULT \'bi\',' +
            'PRIMARY KEY (`usr_id`),' +
            'UNIQUE INDEX `usr_id_UNIQUE` (`usr_id` ASC),' +
            'UNIQUE INDEX `usr_uname_UNIQUE` (`usr_uname` ASC)' +
            //'UNIQUE INDEX `usr_email_UNIQUE` (`usr_email` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_MESSAGE table
        let promise2 = db.execute(
            'CREATE TABLE `db_matcha`.`t_message` (' +
            '`msg_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`msg_content` TEXT NULL,' +
            '`msg_creationDate` DATETIME NOT NULL DEFAULT NOW(),' +
            '`msg_idSender` INT UNSIGNED NOT NULL,' +
            '`msg_idReceiver` INT UNSIGNED NOT NULL,' +
            'PRIMARY KEY (`msg_id`),' +
            'UNIQUE INDEX `msg_id_UNIQUE` (`msg_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_IMAGE table
        let promise3 = db.execute(
            'CREATE TABLE `db_matcha`.`t_image` (' +
            '`image_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`image_path` VARCHAR(255) NOT NULL,' +
            '`image_idUser` INT UNSIGNED NOT NULL,' +
            'PRIMARY KEY (`image_id`),' +
            'UNIQUE INDEX `image_id_UNIQUE` (`image_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_INTEREST table
        let promise4 = db.execute(
            'CREATE TABLE `db_matcha`.`t_interest` (' +
            '`interest_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`interest_name` VARCHAR(255) NOT NULL,' +
            'PRIMARY KEY (`interest_id`),' +
            'UNIQUE INDEX `interest_id_UNIQUE` (`interest_id` ASC),' +
            'UNIQUE INDEX `interest_name_UNIQUE` (`interest_name` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_NOTIFICATION table
        let promise5 = db.execute(
            'CREATE TABLE `db_matcha`.`t_notification` (' +
            '`notif_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`notif_creationDate` DATETIME NOT NULL DEFAULT NOW(),' +
            '`notif_consulted` TINYINT NOT NULL DEFAULT 0,' +
            '`notif_category` VARCHAR(45) NOT NULL,' +
            '`notif_idUser` INT UNSIGNED NOT NULL,' +
            '`notif_idOther` INT UNSIGNED NOT NULL,' +
            '`notif_message` VARCHAR(255) NOT NULL,' +
            'PRIMARY KEY (`notif_id`),' +
            'UNIQUE INDEX `notif_id_UNIQUE` (`notif_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_USERINTEREST table
        let promise6 = db.execute(
            'CREATE TABLE `db_matcha`.`t_userInterest` (' +
            '`userInterest_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`userInterest_idUser` INT UNSIGNED NOT NULL,' +
            '`userInterest_idInterest` INT UNSIGNED NOT NULL,' +
            'PRIMARY KEY (`userInterest_id`),' +
            'UNIQUE INDEX `userInterest_id_UNIQUE` (`userInterest_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_VISIT table
        let promise7 = db.execute(
            'CREATE TABLE `db_matcha`.`t_visit` (' +
            '`visit_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`visit_idVisited` INT UNSIGNED NOT NULL,' +
            '`visit_idVisitor` INT UNSIGNED NOT NULL,' +
            '`visit_date` DATETIME DEFAULT NOW() NOT NULL,' +
            'PRIMARY KEY (`visit_id`),' +
            'UNIQUE INDEX `visit_id_UNIQUE` (`visit_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_LIKE table
        let promise8 = db.execute(
            'CREATE TABLE `db_matcha`.`t_like` (' +
            '`like_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`like_idLiked` INT UNSIGNED NOT NULL,' +
            '`like_idLiker` INT UNSIGNED NOT NULL,' +
            '`like_date` DATETIME DEFAULT NOW() NOT NULL,' +
            'PRIMARY KEY (`like_id`),' +
            'UNIQUE INDEX `like_id_UNIQUE` (`like_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_BLOCK table
        let promise9 = db.execute(
            'CREATE TABLE `db_matcha`.`t_block` (' +
            '`block_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`block_idBlocked` INT UNSIGNED NOT NULL,' +
            '`block_idBlocker` INT UNSIGNED NOT NULL,' +
            '`block_date` DATETIME DEFAULT NOW() NOT NULL,' +
            'PRIMARY KEY (`block_id`),' +
            'UNIQUE INDEX `block_id_UNIQUE` (`block_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_REPORT table
        let promise10 = db.execute(
            'CREATE TABLE `db_matcha`.`t_report` (' +
            '`report_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`report_idReported` INT UNSIGNED NOT NULL,' +
            '`report_idReporter` INT UNSIGNED NOT NULL,' +
            '`report_date` DATETIME DEFAULT NOW() NOT NULL,' +
            'PRIMARY KEY (`report_id`),' +
            'UNIQUE INDEX `report_id_UNIQUE` (`report_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );

        // T_MATCH table
        let promise11 = db.execute(
            'CREATE TABLE `db_matcha`.`t_match` (' +
            '`match_id` INT UNSIGNED NOT NULL AUTO_INCREMENT,' +
            '`match_id1` INT UNSIGNED NOT NULL,' +
            '`match_id2` INT UNSIGNED NOT NULL,' +
            '`match_date` DATETIME DEFAULT NOW(),' +
            'PRIMARY KEY (`match_id`),' +
            'UNIQUE INDEX `match_id_UNIQUE` (`match_id` ASC)' +
            ')' +
            'ENGINE=InnoDB;'
        );
        return (Promise.all([promise1, promise2, promise3, promise4, promise5, promise6, promise7, promise8, promise9, promise10, promise11]));
    })
    .then(result => {
        // T_IMAGE fk
        let promise1 = db.execute(
            'ALTER TABLE `db_matcha`.`t_image` ' +
            'ADD CONSTRAINT FK_ImageUser ' +
            'FOREIGN KEY (`image_idUser`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_MESSAGE fk
        let promise2 = db.execute(
            'ALTER TABLE `db_matcha`.`t_message` ' +
            'ADD CONSTRAINT FK_MessageSender ' +
            'FOREIGN KEY (`msg_idSender`) REFERENCES `db_matcha`.`t_user`(usr_id); ');
        let promise3 = db.execute(
            'ALTER TABLE `db_matcha`.`t_message` ' +
            'ADD CONSTRAINT FK_MessageReceiver ' +
            'FOREIGN KEY (`msg_idReceiver`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_USERINTEREST fk
        let promise4 = db.execute(
            'ALTER TABLE `db_matcha`.`t_userInterest` ' +
            'ADD CONSTRAINT FK_InterestUser ' +
            'FOREIGN KEY (`userInterest_idUser`) REFERENCES `db_matcha`.`t_user`(usr_id);');
        let promise5 = db.execute(
            'ALTER TABLE `db_matcha`.`t_userInterest` ' +
            'ADD CONSTRAINT FK_UserInterest ' +
            'FOREIGN KEY (`userInterest_idInterest`) REFERENCES `db_matcha`.`t_interest`(interest_id);'
        );

        // T_NOTIFICATION fk
        let promise6 = db.execute(
            'ALTER TABLE `db_matcha`.`t_notification` ' +
            'ADD CONSTRAINT FK_notifUser ' +
            'FOREIGN KEY (`notif_idUser`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_VISIT fk
        let promise7 = db.execute(
            'ALTER TABLE `db_matcha`.`t_visit` ' +
            'ADD CONSTRAINT FK_Visited ' +
            'FOREIGN KEY (`visit_idVisited`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_LIKE fk
        let promise8 = db.execute(
            'ALTER TABLE `db_matcha`.`t_like` ' +
            'ADD CONSTRAINT FK_Liker ' +
            'FOREIGN KEY (`like_idLiker`) REFERENCES `db_matcha`.`t_user`(usr_id);');
        let promise9 = db.execute(
            'ALTER TABLE `db_matcha`.`t_like` ' +
            'ADD CONSTRAINT FK_Liked ' +
            'FOREIGN KEY (`like_idLiked`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_BLOCK fk
        let promise10 = db.execute(
            'ALTER TABLE `db_matcha`.`t_block` ' +
            'ADD CONSTRAINT FK_Blocker ' +
            'FOREIGN KEY (`block_idBlocker`) REFERENCES `db_matcha`.`t_user`(usr_id);');
        let promise11 = db.execute(
            'ALTER TABLE `db_matcha`.`t_block` ' +
            'ADD CONSTRAINT FK_Blocked ' +
            'FOREIGN KEY (`block_idBlocked`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_REPORT fk
        let promise12 = db.execute(
            'ALTER TABLE `db_matcha`.`t_report` ' +
            'ADD CONSTRAINT FK_Reporter ' +
            'FOREIGN KEY (`report_idReporter`) REFERENCES `db_matcha`.`t_user`(usr_id);');
        let promise13 = db.execute(
            'ALTER TABLE `db_matcha`.`t_report` ' +
            'ADD CONSTRAINT FK_Reported ' +
            'FOREIGN KEY (`report_idReported`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );

        // T_MATCH fk
        let promise14 = db.execute(
            'ALTER TABLE `db_matcha`.`t_match` ' +
            'ADD CONSTRAINT FK_match1 ' +
            'FOREIGN KEY (`match_id1`) REFERENCES `db_matcha`.`t_user`(usr_id);');
        let promise15 = db.execute(
            'ALTER TABLE `db_matcha`.`t_match` ' +
            'ADD CONSTRAINT FK_match2 ' +
            'FOREIGN KEY (`match_id2`) REFERENCES `db_matcha`.`t_user`(usr_id);'
        );
        return (Promise.all([
            promise1, promise2, promise3,
            promise4, promise5, promise6,
            promise7, promise8, promise9,
            promise10, promise11, promise12,
            promise13, promise14, promise15
        ]));
    })
    .then(result => {
        console.log('SUCCESS - Database has been created and is ready.');
    })
    .catch(error => {
        return (console.log(error));
    })
    .finally(result => {
        process.exit();
    });