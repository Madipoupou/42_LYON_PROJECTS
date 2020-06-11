<?php

require_once('database.php');

// Turn the public folder rights to writable
chmod('./../public/photos', 0777);

// Creates the Camagru Database

global $DB_DSN_INIT, $DB_DSN, $DB_USER, $DB_PASSWORD;

// Database creation

$db = new PDO($DB_DSN_INIT, $DB_USER, $DB_PASSWORD, array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION));
$db->exec('
    DROP DATABASE IF EXISTS camagru;
    CREATE DATABASE IF NOT EXISTS camagru CHARACTER SET UTF8mb4 COLLATE utf8mb4_bin;
    USE camagru;
');

// Table creation
$db = new PDO(
    $DB_DSN_INIT,
    $DB_USER,
    $DB_PASSWORD,
    array(
        PDO::ATTR_TIMEOUT => 5, // in seconds
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION
    )
);
$db->exec('
    CREATE TABLE photo (
        idPhoto INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        photoName VARCHAR(255) NOT NULL,
        creationDate TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
        idUser INT NOT NULL
    );
');
$db->exec('
    CREATE TABLE user (
        idUser INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        nameUser VARCHAR(255) NOT NULL,
        mailUser VARCHAR(255) NOT NULL,
        passwordUser VARCHAR(255) NOT NULL,
        active BOOLEAN DEFAULT FALSE NOT NULL,
        activationKey VARCHAR(255) NOT NULL,
        forgottenKey VARCHAR(255) NOT NULL,
        creationDate TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL,
        notifStatus BOOLEAN DEFAULT TRUE NOT NULL
    );
');
$db->exec('
    CREATE TABLE clipart (
        idImage INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        nameImage VARCHAR(255) NOT NULL
    );
');
$db->exec('
    CREATE TABLE comment (
        idComment INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        textComment TEXT NOT NULL,
        idUser INT NOT NULL,
        idPhoto INT NOT NULL,
        dateComment TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL
    );
');
$db->exec('
    CREATE TABLE enjoy (
        idEnjoy INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        idUser INT NOT NULL,
        idPhoto INT NOT NULL
    );
');
$db->exec('
    CREATE TABLE follow (
        idFollow INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
        idUser INT NOT NULL,
        idFollower INT NOT NULL
    );
');
$db->exec('
    ALTER TABLE photo
    ADD FOREIGN KEY (idUser) REFERENCES user(idUser)
    ON DELETE CASCADE;
    ALTER TABLE comment
    ADD FOREIGN KEY (idUser) REFERENCES user(idUser)
    ON DELETE CASCADE;
    ALTER TABLE comment
    ADD FOREIGN KEY (idPhoto) REFERENCES photo(idPhoto)
    ON DELETE CASCADE;
    ALTER TABLE enjoy
    ADD FOREIGN KEY (idUser) REFERENCES user(idUser);
    ALTER TABLE enjoy
    ADD FOREIGN KEY (idPhoto) REFERENCES photo(idPhoto)
    ON DELETE CASCADE;
    ALTER TABLE follow
    ADD FOREIGN KEY (idUser) REFERENCES user(idUser)
    ON DELETE CASCADE;
    ALTER TABLE follow
    ADD FOREIGN KEY (idFollower) REFERENCES user(idUser)
    ON DELETE CASCADE;
');

// Data insertion
$db->exec("
    INSERT INTO clipart (nameImage)
    VALUES
        ('clipart_1.png'),
        ('clipart_2.png'),
        ('clipart_3.png'),
        ('clipart_4.png'),
        ('clipart_5.png'),
        ('clipart_6.png');
    INSERT INTO user (nameUser, mailUser, passwordUser, active, activationKey, forgottenKey)
    VALUES
        ('mad', 'mad83@sfr.fr', '7d73388f9b889b1e59642aee80007658a8b3041bc6b5f52cfc5e88c84b04dff67a74e05eb31280ff609177bb27c6093df4d41ebfdf5be8112220f85ae84d0ce4', TRUE, 'aaa', 'bbb');
");