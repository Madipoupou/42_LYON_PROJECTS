<?php

require_once('./model/CommentManager.php');
require_once('./model/EnjoyManager.php');
require_once('./model/PhotoManager.php');
require_once('./model/FollowManager.php');
require_once('./model/UserManager.php');

// Displays error messages
function ft_display_error($error) {
    $title = 'CAMAGRU: Erreur';
    $content = '<h1>Erreur</h1>';
    require_once('./view/standard.php');
}

// Logout function
function ft_logout() {
    session_destroy();
    header('Location: ./index.php');
}

// Test if logged in function
function ft_is_logged() {
    if (!isset($_SESSION['idUser'])) {
        header('Location: ./index.php?action=connect&error=pleaselogin');
        exit();
    }
}