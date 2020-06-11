<?php

require_once('./model/Manager.php');

final class EnjoyManager extends Manager {
    // Get number of like for a given photo
    public function ft_nb_enjoy($idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM enjoy WHERE idPhoto = :idPhoto;');
        $query->execute(array('idPhoto' => $idPhoto));
        return ($query);
    }

    // Get if a given user is enjoying a photo or not
    public function ft_get_enjoy($idUser, $idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT idPhoto AS \'idPhoto\' FROM enjoy WHERE idPhoto = :idPhoto AND idUser = :idUser;');
        $query->execute(array('idPhoto' => $idPhoto, 'idUser' => $idUser));
        return ($query);
    }

    // Add an enjoy from an user about a photo
    public function ft_add_enjoy($idUser, $idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('INSERT INTO enjoy(idPhoto, idUser) VALUES(:idPhoto, :idUser);');
        $query->execute(array('idPhoto' => $idPhoto, 'idUser' => $idUser));
        $query->closeCursor();
    }

    // Remove an enjoy from an user about a photo
    public function ft_remove_enjoy($idUser, $idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('DELETE FROM enjoy WHERE idPhoto = :idPhoto AND idUser = :idUser;');
        $query->execute(array('idPhoto' => $idPhoto, 'idUser' => $idUser));
        $query->closeCursor();
    }
}