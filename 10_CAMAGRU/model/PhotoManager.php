<?php

require_once('./model/Manager.php');

final class PhotoManager extends Manager {
    // Returns all the photo from the DB
    public function ft_photo_all($page_num) {
        $lim = ($page_num - 1) * 5;
        $lim = strval($lim);
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT * FROM photo ORDER BY creationDate DESC LIMIT :lim, 5;');
        $query->bindValue(':lim', (int) $lim, PDO::PARAM_INT);
        $query->execute();
        return ($query);
    }

    // Returns a photo from the DB according to its id
    public function ft_photo_one($idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT * FROM photo WHERE idPhoto = :idPhoto;');
        $query->execute(array('idPhoto' => $idPhoto));
        return ($query);
    }

    // Returns the number of pages (five elements on each page)
    public function ft_max_page() {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM photo;');
        $query->execute();
        return ($query);
    }

    // Returns all the photos from the DB - only for the given user
    public function ft_photo_user($idUser) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT * FROM photo WHERE idUser = :idUser ORDER BY creationDate DESC;');
        $query->execute(array('idUser' => $idUser));
        return ($query);
    }

    // Saves a photo in the database
    public function ft_save_photo($photoName, $idUser) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('INSERT INTO photo(photoName, idUser) VALUES (:photoName, :idUser);');
        $query->execute(array('photoName' => $photoName, 'idUser' => $idUser));
        $query->closeCursor();
    }

    // Returns all the cliparts from the DB
    public function ft_clipart_all() {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT * FROM clipart;');
        $query->execute();
        return ($query);
    }

    // Delete a photo from database according to the photo name and the id of the user
    public function ft_delete_photo($idUser, $photoName) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('DELETE FROM photo WHERE idUser = :idUser AND photoName = :photoName;');
        $query->execute(array('idUser' => $idUser, 'photoName' => $photoName));
        $query->closeCursor();
    }

    // Get the id of a photo's author
    public function ft_get_user_photo($idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT idUser FROM photo WHERE idPhoto = :idPhoto;');
        $query->execute(array('idPhoto' => $idPhoto));
        return ($query);
    }
}