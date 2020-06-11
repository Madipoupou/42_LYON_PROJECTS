<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- stylesheets -->
    <!-- <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.2.1/css/bootstrap.min.css" integrity="sha384-GJzZqFGwb1QTTN6wy59ffF1BuGJpLSa9DkKMp0DgiMDm4iYMj70gZWKYbI706tWS" crossorigin="anonymous"> -->
    <link href="https://stackpath.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">
    <link rel="stylesheet" type="text/css" href="styles/rush.css">
    <!-- favicon -->
    <link rel="icon" type="image/png" href="favicon/favicon-32x32.png" sizes="32x32" />
    <link rel="icon" type="image/png" href="favicon/favicon-16x16.png" sizes="16x16" />
</head>
<!-- Header -->
<header class="header trans_300">

<!-- Top Navigation -->
<div class="top_nav">
    <div class="container">
        <div class="row">
            <div class="col">
                <div class="top_nav_left">Livraison gratuite sur commandes de plus de 42 000€</div>
            </div>
            <div class="col text-right">
                <div class="top_nav_right">
                    <ul class="top_nav_menu">
                        <!-- Mon compte -->
                        <li class="account">
                            <a href="#">
                            Mon Compte
                            <i class="fa fa-angle-down"></i>
                        </a>
                            <ul class="account_selection">
                            <?php
                                if (!isset($_SESSION["user_log"]))
                                {
                                    echo '<li><a href="./login.php"><i class="fa fa-sign-in" aria-hidden="true"></i>Se connecter</a></li>';
                                    echo '<li><a href="./register.php"><i class="fa fa-user-plus" aria-hidden="true"></i>S\'inscrire</a></li>';
                                }
                                else
                                {
                                    echo '<li><a href="./userpage.php"><i class="fa fa-sign-in" aria-hidden="true"></i>Gestion du compte</a></li>';
                                    echo '<li><a href="./controller/logout.php"><i class="fa fa-user-plus" aria-hidden="true"></i>Se déconnecter</a></li>';
                                }
                                ?>
                            </ul>
                        </li>
                    </ul>
                </div>
            </div>
        </div>
    </div>
</div>

<!-- Main Navigation -->

<div class="main_nav_container">
    <div class="container">
        <div class="row">
            <div class="col">
                <div class="logo_container">
                    <img src="images/logo.svg" width="50" height="50" alt="">
                    <a href="../index.php">life<span>shop</span></a>
                </div>
                <nav class="navbar text-right" >
                    <ul class="navbar_menu">
                        <li><a href="../index.php">Accueil</a></li>
                        <li><a href="../catalogue.php">Catalogue</a></li>
                        <li><a href="#" style="color: #fe4c50;">Soldes</a></li>
                        <li><a href="contact.html">Contact</a></li>
                    </ul>
                    <ul class="navbar_user">
                        <li><a href="#"><i class="fa fa-search" aria-hidden="true"></i></a></li>
                        <li><a href="#"><i class="fa fa-user" aria-hidden="true"></i></a></li>
                        <li class="checkout">
                            <a href="panier.php">
                                <i class="fa fa-shopping-cart" aria-hidden="true"></i>
                                <!-- <span id="checkout_items" class="checkout_items">2</span> -->
                            </a>
                        </li>
                    </ul>
                </nav>
            </div>
        </div>
    </div>
</div>
</header>