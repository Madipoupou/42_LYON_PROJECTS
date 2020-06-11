<?php

require_once('./model/CommentManager.php');
require_once('./model/EnjoyManager.php');
require_once('./model/PhotoManager.php');
require_once('./model/FollowManager.php');
require_once('./model/UserManager.php');

// Displays connection form
function ft_display_connect() {
    $title = 'CAMAGRU: Connexion';
    ob_start();
    require_once('./view/connect.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}

// Displays suscribe form
function ft_display_suscribe() {
    $title = 'CAMAGRU: Inscription';
    ob_start();
    require_once('./view/suscribe.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}

// Searching bar
function ft_user_search() {
    $title = 'CAMAGRU: Recherche';
    $content = '<h1>Recherche</h1>';
    require_once('./view/standard.php');
}

// Forgotten password
function ft_forgotten() {
    $title = 'CAMAGRU: Mot de passe oublié';
    ob_start();
    require_once('./view/forgotten.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}

// Reset Password
function ft_reset() {
    // Management of form errors
    if (!isset($_GET['username']) || !isset($_GET['key'])) {
        header('Location: ./index.php?action=connect&error=reset');
        exit();
    }
    if ($_GET['username'] == '' || $_GET['key'] == '') {
        header('Location: ./index.php?action=connect&error=reset');
        exit();
    }
    $pseudo = $_GET['username'];
    $forgottenKey = $_GET['key'];

    // Checks if the user already exists
    $userManager = new Usermanager();
    $query = $userManager->ft_username_exists($pseudo);
    $nb_user = $query->fetch();
    $query->closeCursor();
    if ($nb_user['nb'] == 0) {
        header('Location: ./index.php?action=connect&error=reset');
        exit();
    }

    // Checks if forgotten key corresponds to the user
    $userManager = new Usermanager();
    $query = $userManager->ft_check_forgottenkey($pseudo, $forgottenKey);
    $ok = $query->fetch();
    $query->closeCursor();
    if ($ok['nb'] != 1) {
        header('Location: ./index.php?action=connect&error=reset');
        exit();
    }

    $title = 'CAMAGRU: Réinitialiser mot de passe';
    ob_start();
    require_once('./view/reset.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}