<?php

if (isset($_SESSION['username'])) {
    ?>
    <nav id="myTopnav">
        <div class="left_nav">
            <a href="./index.php?action=ownprofile"><img src="./public/img/logo.png" alt="logo">CAMAGRU</a>
            <a href="./index.php?action=gallery">Galerie</a>
            <a href="./index.php?action=create">Créer</a>
            <a href="./index.php?action=logout">Déconnexion</a>
            <a href="javascript:void(0);" class="icon" onclick="myFunction()">
                <i class="fa fa-bars"></i>
            </a>
        </div>
        <div class="right_nav">
            <form action="./index.php" method="GET" class="form-inline my-2 my-lg-0">
                <input type="hidden" name="action" value="search">
                <input class="search_input form-control mr-sm-2" type="search" placeholder="Rechercher un membre" aria-label="Search" name="user" id="search_input">
                <button class="btn btn-primary my-2 my-sm-0" type="submit">Ok</button>
            </form>
        </div>
    </nav>
    <div id="responsive_nav" class="responsive_nav">
        <a href="./index.php?action=gallery">Galerie</a>
        <a href="./index.php?action=create">Créer</a>
        <a href="./index.php?action=logout">Déconnexion</a>
    </div>
    <?php
} else {
    ?>
    <nav id="myTopnav">
        <div class="left_nav">
            <a href="./index.php"><img src="./public/img/logo.png" alt="logo">CAMAGRU</a>
            <a href="./index.php?action=gallery">Galerie</a>
            <a href="./index.php?action=connect">Connexion</a>
            <a href="./index.php?action=suscribe">Inscription</a>
            <a href="javascript:void(0);" class="icon" onclick="myFunction()">
                <i class="fa fa-bars"></i>
            </a>
        </div>
        <div class="right_nav">
            <form action="./index.php" method="GET" class="form-inline my-2 my-lg-0">
                <input type="hidden" name="action" value="search">
                <input class="search_input form-control mr-sm-2" type="search" placeholder="Rechercher un membre" aria-label="Search" name="user" id="search_input">
                <button class="btn btn-primary my-2 my-sm-0" type="submit">Ok</button>
            </form>
    </nav>
    <div id="responsive_nav" class="responsive_nav">
        <a href="./index.php?action=gallery">Galerie</a>
        <a href="./index.php?action=connect">Connexion</a>
        <a href="./index.php?action=suscribe">Inscription</a>
    </div>
    <?php
}