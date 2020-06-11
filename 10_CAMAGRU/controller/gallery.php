<?php

require_once('./model/CommentManager.php');
require_once('./model/EnjoyManager.php');
require_once('./model/PhotoManager.php');
require_once('./model/FollowManager.php');
require_once('./model/UserManager.php');


// Displays the gallery of the website composed of all the photos ranked by date
function ft_display_gallery() {
    $title = 'CAMAGRU: Galerie d\'accueil';
    $photoManager = new PhotoManager();
    $enjoyManager = new EnjoyManager();
    $commentManager = new CommentManager();

    // Generating the pagination panel
    $query = $photoManager->ft_max_page();
    $max_page = intval($query->fetch()['nb']) / 5;
    $max_page_temp = intval($max_page);
    if ($max_page_temp == $max_page) {
        $max_page = $max_page_temp;
    } else {
        $max_page = $max_page_temp + 1;
    }
    $query->closeCursor();
    if (isset($_GET['page'])) {
        $page_num = intval($_GET['page']);
        if ($page_num <= 0 || $page_num > $max_page) {
            $page_num = 1;
        }
    } else {
        $page_num = 1;
    }
    $pagination = '';
    if ($page_num > 1) {
        $pagination = $pagination . '<a href="./index.php?action=gallery&page=' . ($page_num - 1) . '"><img src="./public/img/left_arrow.png" /></a>';
    } else {
        $pagination = $pagination . '<div><img src="./public/img/left_arrow.png" /></div>';
    }
    $pagination = $pagination . '<p>' . $page_num .'</p>';
    if ($page_num < $max_page) {
        $pagination = $pagination . '<a href="./index.php?action=gallery&page=' . ($page_num + 1) . '"><img src="./public/img/right_arrow.png" /></a>'; 
    } else {
        $pagination = $pagination . '<div><img src="./public/img/right_arrow.png" /></div>'; 
    }

    // Storing all the photos in a variable
    $query = $photoManager->ft_photo_all($page_num);
    $photos = '';
    while ($temp = $query->fetch()) {
        $photos = $photos . '
            <div class="gallery_image">
                <img class="gallery_image_pic" src="./public/photos/' . htmlspecialchars($temp['photoName']) . '" />
        ';
        $query_enjoy = $enjoyManager->ft_nb_enjoy($temp['idPhoto']);
        $nb_enjoy = $query_enjoy->fetch()['nb'];
        $query_enjoy->closeCursor();
        $query_comment = $commentManager->ft_nb_comment($temp['idPhoto']);
        $nb_comment = $query_comment->fetch()['nb'];
        $query_comment->closeCursor();
        if (isset($_SESSION['idUser'])) {
            $photos = $photos . '
                <div class="gallery_image_panel">
                    <table>
                        <tr>
                            <td align="left"><img class="enjoy_img" src="./public/img/like.png" onclick="ft_enjoy(' . $temp['idPhoto'] . ')" /><span class="nb" id="nb_p_' . $temp['idPhoto'] . '">' . $nb_enjoy . '</span></td>
                            <td align="right"><span class="nb">' . $nb_comment . '</span><a href="./index.php?action=comment&idPhoto=' . $temp['idPhoto'] . '"><img src="./public/img/comment.png" /></a></td>
                        </tr>
                    </table>
                </div>
            ';
        } else {
            $photos = $photos . '
                <div class="gallery_image_panel">
                    <table>
                        <tr>
                            <td align="left"><img src="./public/img/like.png" /><span class="nb">' . $nb_enjoy . '</span></td>
                            <td align="right"><span class="nb">' . $nb_comment . '</span><img src="./public/img/comment.png" /></td>
                        </tr>
                    </table>
                </div>
            ';
        }
        $photos = $photos . '      
            </div>
        ';
    }
    $query->closeCursor();

    ob_start();
    require_once('./view/gallery.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}


// Displays the photo creation page
function ft_display_create() {
    ft_is_logged();
    $photoManager = new PhotoManager();
    $title = 'CAMAGRU: Création d\'image';
    $cliparts = '';
    $query = $photoManager->ft_clipart_all();
    while ($temp = $query->fetch()) {
        $cliparts = $cliparts . '<img src="./public/cliparts/' . $temp['nameImage'] . '" alt="clipart" class="clipart_list" onclick="addPicture(this)" />';
    }
    $query->closecursor();
    $query = $photoManager->ft_photo_user($_SESSION['idUser']);
    $user_gallery = '';
    $i = 0;
    while ($temp = $query->fetch()) {
        if ($i == 0) {
            $user_gallery = $user_gallery . '<p>Cliquer pour supprimer</p>';
        }
        $user_gallery = $user_gallery . '<img src="./public/photos/' . $temp['photoName'] . '" alt="photo" class="photo_hist" onclick="deletePicture(this)" />';
        $i++;
    }
    if ($user_gallery == '') {
        $user_gallery = '<p>Vous n\'avez aucune image</p>';
    }
    $query->closecursor();
    ob_start();
    require_once('./view/create.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}


// Checks if the creation is ok, then saves the picture
function ft_create_checker() {
    ft_is_logged();
    // Checking for expected inputs
    if (!isset($_POST['image']) || !isset($_POST['overlay'])) {
        header('Location: ./index.php?action=create&error=empty');
        exit();
    }
    if ($_POST['image'] == '' || $_POST['overlay'] == '') {
        header('Location: ./index.php?action=create&error=empty');
        exit();
    }

    // Overlay initialization
    $overlay = './public/cliparts/' . $_POST['overlay'];
    echo($overlay);
    if ($_POST['overlay'] === 'none' || !file_exists($overlay)) {
        header('Location: ./index.php?action=create&error=empty');
        exit();
    }

    // Creating necessary variables
    $username = $_SESSION['username'];
    $idUser = $_SESSION['idUser'];
    $photoManager = new PhotoManager();
    $img = $_POST['image'];
    $folderPath = "./public/photos/";
    $fileName = $username . '_' . $idUser . '_' . uniqid() . '.png';

    // Creating and saving the file into server
    $image_parts = explode(";base64,", $img);
    $image_type_aux = explode("image/", $image_parts[0]);
    $image_type = $image_type_aux[1];
    $image_base64 = base64_decode($image_parts[1]);
  
    $file = $folderPath . $fileName;
    file_put_contents($file, $image_base64);

    // Saving the photo in the database
    $photoManager->ft_save_photo($fileName, $idUser);
    
    // Creating the image superposition
    // Traitement de l'image source
    if ($_POST['overlay'] !== 'none' && file_exists($overlay)) {
        $source = imagecreatefrompng($overlay);
        $largeur_source = imagesx($source);
        $hauteur_source = imagesy($source);
        imagealphablending($source, true);
        imagesavealpha($source, true);

        // Traitement de l'image destination
        $destination = imagecreatefrompng($file);
        $destination = imagescale($destination, 320, 240);
        $largeur_destination = imagesx($destination);
        $hauteur_destination = imagesy($destination);

        // Calcul des coordonnées pour placer l'image source dans l'image de destination
        $destination_x = ($largeur_destination - $largeur_source)/2;
        $destination_y =  ($hauteur_destination - $hauteur_source)/2;

        // On place l'image source dans l'image de destination
        //imagecopymerge($destination, $source, $destination_x, $destination_y, 0, 0, $largeur_source, $hauteur_source, 100);
        imagecopy($destination, $source, $destination_x, $destination_y, 0, 0, $largeur_source, $hauteur_source);
        
        // On affiche l'image de destination
        imagepng($destination, $file);
        
        imagedestroy($source);
        imagedestroy($destination);
    }

    //header('Location: ./index.php?action=create');
}


// Delete a picture from the database
function ft_delete_picture() {
    // Checking if the needed variables are set and if user is auth
    if (!isset($_SESSION['idUser']) || !isset($_POST['photoName'])) {
        return ('Error');
        exit();
    }

    // Deleting the picture form DB - Checking if the photo belongs to user auth. and if picture exists
    $idUser = $_SESSION['idUser'];
    $username = $_SESSION['username'];
    $photoName = $_POST['photoName'];
    $photoManager = new PhotoManager();
    
    if (!file_exists('./public/photos/' . $photoName)) {
        return ('Error');
        exit();
    }
    $photoManager->ft_delete_photo($idUser, $photoName);
    unlink('./public/photos/' . $photoName);


    echo($idUser . ' ' . $username . ' ' . $photoName);
}


// Add or Remove a "enjoy" from a logged in user about a given photo
function ft_enjoy() {
    // Checking if the needed variables are set and if user is auth
    if (!isset($_SESSION['idUser']) || !isset($_POST['idPhoto'])) {
        header('Location: ./index.php');
        exit();
    }

    // Deleting the picture form DB - Checking if the photo belongs to user auth. and if picture exists
    $idUser = $_SESSION['idUser'];
    $idPhoto = $_POST['idPhoto'];
    $enjoyManager = new EnjoyManager();

    // Checking if the user is already liking the photo
    $query = $enjoyManager->ft_get_enjoy($idUser, $idPhoto);
    $already_enjoyed = $query->fetch()['idPhoto'];
    $query->closeCursor();

    // Adding or removing a like according to previous result
    if ($already_enjoyed != $idPhoto) {
        $enjoyManager->ft_add_enjoy($idUser, $idPhoto);
    } else {
        $enjoyManager->ft_remove_enjoy($idUser, $idPhoto);
    }

    // Returning the number of enjoy for the photo
    $query_enjoy = $enjoyManager->ft_nb_enjoy($idPhoto);
    $nb_enjoy = $query_enjoy->fetch()['nb'];
    $query_enjoy->closeCursor();
    echo($nb_enjoy);
}


// Displays the comment page
function ft_comment() {
    ft_is_logged();
    $title = 'CAMAGRU: Commentaires';
    $photoManager = new PhotoManager();

    // Checking if idPhoto is correct (sent in the url)
    if (!isset($_GET['idPhoto'])) {
        header('Location: ./index.php');
        exit();
    }
    $idPhoto = $_GET['idPhoto'];
    $query = $photoManager->ft_photo_one($idPhoto);
    $current_photo = $query->fetch();
    $query->closeCursor();
    if (!$current_photo || !file_exists('./public/photos/' . $current_photo['photoName'])) {
        header('Location: ./index.php');
        exit();
    }

    // Creating the photo division
    $query = $photoManager->ft_photo_one($idPhoto);
    $photo = $query->fetch();
    $query->closeCursor();
    $photo_html = '';
    if (!$photo) {
        header('Location: ./index.php');
        exit();
    }
    $photo_html = $photo_html . '
        <img class="comment_image_pic" src="./public/photos/' . htmlspecialchars($photo['photoName']) . '" />
    ';

    // Creating the comment section
    $commentManager = new CommentManager();
    $query = $commentManager->ft_comment_all($idPhoto);
    $comments_html = '';
    while ($temp = $query->fetch()) {
        $comments_html = $comments_html . '
            <div class="comments_display_comment">
                <h5>' . htmlspecialchars($temp['nameUser']) . ':</h5>
                <p>' . htmlspecialchars($temp['textComment']) . '</p>
            </div>
        ';
    }
    if ($comments_html == '') {
        $comments_html = '<p>Aucun commentaire...</p>';
    }

    ob_start();
    require_once('./view/comment.php');
    $content = ob_get_clean();
    require_once('./view/standard.php');
}

// Check the comment
function ft_comment_checker($root) {
    ft_is_logged();
    if (!isset($_POST['textComment']) || !isset($_POST['idPhoto']) || $_POST['textComment'] == '') {
        header('Location: ./index.php');
        exit();
    }
    $textComment = $_POST['textComment'];
    $idUser = $_SESSION['idUser'];
    $idPhoto = $_POST['idPhoto'];

    // Checking if the given picture exists
    $photoManager = new PhotoManager();
    $query = $photoManager->ft_photo_one($idPhoto);
    $photo = $query->fetch();
    $query->closeCursor();
    if (!$photo) {
        header('Location: ./index.php');
        exit();
    }
    $commentManager = new CommentManager();
    $commentManager->ft_add_comment($idPhoto, $idUser, $textComment);

    // Getting the information from the photo's author
    $query = $photoManager->ft_get_user_photo($idPhoto);
    $idAuthor = $query->fetch()['idUser'];
    $query->closeCursor();
    $userManager = new UserManager();
    $query = $userManager->ft_user_info(array('idUser' => $idAuthor));
    $temp = $query->fetch();
    $mailAuthor = $temp['mailUser'];
    $notifStatus = $temp['notifStatus'];
    $query->closeCursor();echo('mail: ' . $mailAuthor . ' notif: ' . $notifStatus);

    // Sending the notification email (if necessary)
    if ($notifStatus == '1') {
        $subject = "CAMAGRU: Notification" ;
        $head = "From: notification@camagru.com" ;
        $content =
            'L\'une de vos images a reçu un commentaire!
            Pour le consulter, cliquez sur le lien suivant:
            
            '. $root .'?action=comment&idPhoto=' . $idPhoto . '
            
            ---------------
            Ceci est un mail automatique, merci de ne pas y repondre.';
        $ok = mail($mailAuthor, $subject, $content, $head) ;
        if (!$ok) {
            header('Location: ./index.php?action=comment&idPhoto=' . $idPhoto);
            exit();
        }
    }
    header('Location: ./index.php?action=comment&idPhoto=' . $idPhoto);
}