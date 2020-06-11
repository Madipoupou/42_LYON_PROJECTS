<?php

require_once('./model/Manager.php');

final class CommentManager extends Manager {
    // Get number of comments for a given photo
    public function ft_nb_comment($idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('SELECT COUNT(*) AS \'nb\' FROM comment WHERE idPhoto = :idPhoto;');
        $query->execute(array('idPhoto' => $idPhoto));
        return ($query);
    }

    // Get all the comments about a given photo
    public function ft_comment_all($idPhoto) {
        $db = $this->ft_connect_db();
        $query = $db->prepare(
            'SELECT textComment, nameUser ' .
            'FROM comment ' .
            'INNER JOIN user ON comment.idUser = user.idUser ' .
            'WHERE idPhoto = :idPhoto ' .
            'ORDER BY dateComment DESC;'
        );
        $query->execute(array('idPhoto' => $idPhoto));
        return ($query);
    }

    // Add a comment into the database
    public function ft_add_comment($idPhoto, $idUser, $textComment) {
        $db = $this->ft_connect_db();
        $query = $db->prepare('INSERT INTO comment(idPhoto, idUser, textComment) VALUES(:idPhoto, :idUser, :textComment);');
        $query->execute(array('idPhoto' => $idPhoto, 'idUser' => $idUser, 'textComment' => $textComment));
        $query->closeCursor();
    }
}