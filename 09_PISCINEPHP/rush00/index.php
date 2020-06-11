<?php

session_start();
if (!isset($_SESSION["installed"]))
	require_once("./install.php");
include 'inc/header.php';
?>
<html lang="fr">
<head>
<title>lifeshop | Les meilleurs organes du Rhône.</title>
</head>
<body>
	<div class="body_container">
		<div class="main_slider" style="background-image:url(https://cdn.intra.42.fr/users/large_tiperoul.JPG)">
			<div class="container fill_height">
				<div class="row align-items-center fill_height">
					<div class="col">
						<div class="main_slider_content">
							<h6>Collection d'hiver 2019</h6>
							<h1 style="-webkit-text-stroke: 1px black;" class="text-light">Économisez jusqu'à 20% sur les nouveaux arrivages !</h1>
							<div class="red_button shop_now_button"><a href="./catalogue.php">Parcourir</a></div>
						</div>
					</div>
					<div>
						<span class="badge badge-success text" style="position: absolute; font-size: 1rem;">A++</span>
						<img src="https://i.imgur.com/1De20qN.png" width="200" height="auto" class="p-5 badge badge-pill badge-light float-right d-block">
					</div>
				</div>
			</div>
		</div>
        <div class="banner">
            <div class="container">
                <div class="row">
                    <div class="col">
                        <div class="banner_item align-items-center" style="background-image:url(https://cdn.intra.42.fr/users/large_sciliber.jpg)">
                            <div class="banner_category">
                                <a href="./catalogue.php">Femmes</a>
                            </div>
                        </div>
                    </div>
                    <div class="col">
                        <div class="banner_item align-items-center" style="background-image:url(https://cdn.intra.42.fr/users/large_cpieri.jpg)">
                            <div class="banner_category">
                                <a href="./catalogue.php">Hommes</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
		<?php

			// if (!isset($_SESSION["user_log"]))
			// {
			// 	echo('<p><a href="./login.php">Connexion</a></p>');
			// 	echo('<p><a href="./register.php">Inscription</a></p>');
			// }
			// else
			// {
			// 	echo("<p>Bienvenue ".$_SESSION["user_log"]."</p>");
			// 	if ($_SESSION["user_type"] == 1)
			// 		echo('<p><a href="./admin.php">Panneau d\'administration</a></p>');
			// 	echo('<p><a href="./controller/logout.php">Déconnexion</a></p>');
			// }
			include 'inc/avantages.php';
		?>
	</div>
</body>
<?php include 'inc/footer.php'; ?>
</html>