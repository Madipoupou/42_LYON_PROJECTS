<?php

require_once('./model/CommentManager.php');
require_once('./model/EnjoyManager.php');
require_once('./model/PhotoManager.php');
require_once('./model/FollowManager.php');
require_once('./model/UserManager.php');

// Displays the profile of an user
function ft_display_user($username) {
    $title = 'CAMAGRU: Page utilisateur';
    $content = '<h1>Page utilisateur</h1>';
    require_once('./view/standard.php');
}

// Displays the profile of a logged in user
function ft_display_userpage($username) {
    ft_is_logged();
    $username = $_SESSION['username'];
    $title = 'CAMAGRU: Page personnelle';

    // Getting user information
    $userManager = new UserManager();
    $query = $userManager->ft_user_info(array('username' => $username));
    $userInfo = $query->fetch();
    $query->closeCursor();

    ob_start();
    require_once('./view/ownprofile.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}