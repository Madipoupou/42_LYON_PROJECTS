<?php

session_start();
require_once("./lib/ft_db_connect.php");
$link = ft_db_connect("lifeshop");
if (!$link)
{
    echo("Erreur - Impossible de se connecter à la BDD.\n");
    exit();
}
$request = "
    SELECT *
    FROM organe
    INNER JOIN categorie_organe ON organe.id_orgcat = categorie_organe.id_orgcat
    INNER JOIN proprietaire ON organe.id_prop = proprietaire.id_prop
";
$request2 = "
	SELECT *
	FROM categorie_organe;
";
$rep2 = mysqli_query($link, $request2);
$cpt = 0;
while ($tab = mysqli_fetch_array($rep2))
{
	if (isset($_POST[htmlspecialchars(utf8_encode($tab["nom_orgcat"]))]))
	{
		if ($cpt == 0)
			$request .= "\nWHERE nom_orgcat = '".$tab["nom_orgcat"]."'";
		else
			$request .= " OR nom_orgcat = '".$tab["nom_orgcat"]."'";
		$cpt++;
	}
}
$request .= "\nORDER BY prix_organe ASC;";
$rep = mysqli_query($link, $request);
include 'inc/header.php';
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
	<title>Catalogue</title>
</head>
<body>
<div class="body_container">
	<div class="product_section">
		<div class="container">
			<div class="breadcrumbs">
				<ul>
					<li><a href="index.html">Accueil</a></li>
					<li class="active"><a href="index.html"><i class="fa fa-angle-right" aria-hidden="true"></i>Catalogue</a></li>
				</ul>
			</div>
			<div class="sidebar">
				<div class="sidebar_title">
					<h5>Choisir la catégorie</h5>
				</div>
				<form action="./catalogue.php" method="POST">
					<ul class="sidebar_categories">
					<?php
					$rep2 = mysqli_query($link, $request2);
					while ($tab = mysqli_fetch_array($rep2))
					{
						echo('<li><input style="margin-right: 10px;" type="checkbox" name="'.htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'" value="'.htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'" id="');
						echo(htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'">');
						echo('<label for="'.htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'">'.ucfirst(htmlspecialchars(utf8_encode($tab["nom_orgcat"]))));
						echo('</label></li>');
					}
					?>
					</ul>
					<button type="submit" name="submit" class="btn red_button text-light">OK</button>
				</form>
			</div>
			<div class="main_content">
				<div class="row">
					<?php
					while ($tab = mysqli_fetch_array($rep))
					{
						echo '<div class="col product text-center align-items-center">';
						echo('<a href="./article.php?article="'.intval($tab["id_organe"]).'">');
						if (file_exists('./images/'.htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'.png'))
							echo('<img width="250" height="250" src="./images/'.htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'.png" alt="'.htmlspecialchars(utf8_encode($tab["nom_orgcat"])).'" />');
						else
							echo('<img src="./images/default_image.png" alt="default" />');
						echo("</a>");
						echo('<h6 class="product_name">'.ucfirst(htmlspecialchars(utf8_encode($tab["nom_orgcat"]))).'</h6>');
						echo(htmlspecialchars(utf8_encode($tab["nom_prop"])));
						echo('<div class="product_price">'.htmlspecialchars($tab["prix_organe"]).'€</div>');
						echo('<button class="btn red_button"><a href="./panier.php?nom=');
						echo(utf8_encode($tab["nom_orgcat"]));
						echo('&prix=');
						echo($tab["prix_organe"]);
						echo('&prop=');
						echo($tab["login_prop"]);
						echo('">Ajouter au panier</a></button>');
						echo '</div>';
					}
					?>
				</div>
			</div>
		</div>
	</div>
	<?php include 'inc/avantages.php' ?>
</div>
</body>
<?php include 'inc/footer.php'; ?>
</html>