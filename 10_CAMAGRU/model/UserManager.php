<?php

require_once('./model/Manager.php');

final class UserManager extends Manager {
    // Returns all the information about a given user in the database (according to mail or pseudo)
    public function ft_user_info($tab) {
        $db = $this->ft_connect_db();
        if (isset($tab['mail'])) {
            $query = $db->prepare('SELECT * FROM user WHERE mailUser = :mailUser;');
            $query->execute(array('mailUser' => $tab['mail']));
        }
        else if (isset($tab['username'])) {
            $query = $db->prepare('SELECT * FROM user WHERE nameUser = :nameUser;');
            $query->execute(array('nameUser' => $tab['username']));
        }
        else if (isset($tab['idUser'])) {
            $query = $db->prepare('SELECT * FROM user WHERE idUser = :idUser;');
            $query->execute(array('idUser' => $tab['idUser']));
        }
        return ($query);
    }

    // Adds a new user in the database
    public function ft_adduser($username, $mail, $password, $activationKey, $forgottenKey) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('INSERT INTO user(nameUser, mailUser, passwordUser, activationKey, forgottenKey) VALUES (:nameUser, :mailUser, :passwordUser, :activationKey, :forgottenKey);');
        $query->execute(array('nameUser' => $username, 'mailUser' => $mail, 'passwordUser' => $password, 'activationKey' => $activationKey, 'forgottenKey' => $forgottenKey));
        $query->closeCursor();
    }

    // Returns the number of user matching the given username
    public function ft_username_exists($username) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM user WHERE nameUser = :nameUser;');
        $query->execute(array('nameUser' => $username));
        return ($query);
    }

    // Returns the number of user matching the giver mail
    public function ft_mail_exists($mail) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM user WHERE mailUser = :mailUser;');
        $query->execute(array('mailUser' => $mail));
        return ($query);
    }

    // Checks if the password of the given user is correct
    public function ft_check_password($username, $pwd) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM user WHERE nameUser = :nameUser AND passwordUser = :password;');
        $query->execute(array('nameUser' => $username, 'password' => $pwd));
        return ($query);
    }

    // Checks if the username corresponds to an active account
    public function ft_check_active($username) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM user WHERE nameUser = :nameUser AND active = TRUE;');
        $query->execute(array('nameUser' => $username));
        return ($query);
    }

    // Checks if the activationkey of the given user is correct
    public function ft_check_activationkey($username, $key) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM user WHERE nameUser = :nameUser AND activationKey = :activationKey;');
        $query->execute(array('nameUser' => $username, 'activationKey' => $key));
        return ($query);
    }

    // Checks if the forgottenkey of the given user is correct
    public function ft_check_forgottenkey($username, $key) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM user WHERE nameUser = :nameUser AND forgottenKey = :forgottenKey;');
        $query->execute(array('nameUser' => $username, 'forgottenKey' => $key));
        return ($query);
    }

    // Activates the given user in the DB
    public function ft_activate($username) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('UPDATE user SET active = TRUE WHERE nameUser = :nameUser;');
        $query->execute(array('nameUser' => $username));
        $query->closeCursor();
    }

    // Updates the password in the database
    public function ft_update_pwd($username, $pwd, $key) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('UPDATE user SET passwordUser = :pwd, forgottenKey = :forgottenKey WHERE nameUser = :nameUser;');
        $query->execute(array('nameUser' => $username, 'pwd' => $pwd, 'forgottenKey' => $key));
        $query->closeCursor();
    }

    // Updates the user in the database
    public function ft_update_user($idUser, $pseudo, $mail, $pwd, $notifStatus) {
        $db = $this->ft_connect_db();
        if ($pwd != '') {
            $query = $db->prepare('UPDATE user SET nameUser = :pseudo, mailUser = :mail, passwordUser = :pwd, notifStatus = :notifStatus WHERE idUser = :idUser;');
            $query->execute(array('pseudo' => $pseudo, 'mail' => $mail, 'pwd' => $pwd, 'notifStatus' => $notifStatus, 'idUser' => $idUser));
        } else {
            $query = $db->prepare('UPDATE user SET nameUser = :pseudo, mailUser = :mail, notifStatus = :notifStatus WHERE idUser = :idUser;');
            $query->execute(array('pseudo' => $pseudo, 'mail' => $mail, 'notifStatus' => $notifStatus, 'idUser' => $idUser));
        }
        $query->closeCursor();
    }
}