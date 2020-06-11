<?php

session_start();
if (!isset($_SESSION["id_log"]))
    header("Location: ./index.php");
require_once("lib/ft_db_connect.php");

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Lifeshop: Gestion Utilisateur</title>
</head>
<body>
    <h2>Vos informations:</h2>
   <?php
    
    $link = ft_db_connect("lifeshop");
    $id = $_SESSION["id_log"];
    $request = "SELECT * FROM membre WHERE id_membre = $id;";
	$rep = mysqli_query($link, $request);
	$array = mysqli_fetch_array($rep);
	?>
	<table>
		<tr>
			<td rowspan="5">
				<?php
				if ($array["url_membre"] == NULL)
					echo('<img src="./images/default_image.png" alt="default">');
				else
				{
					echo('<img src="');
					echo($array["url_membre"]);
					echo('" alt="user">');
				}
				?>
			</td>
			<td><?=$array["nom_membre"]?></td>
		</tr>
		<tr>
			<td><?=$array["prenom_membre"]?></td>
		</tr>
		<tr>
			<td><?=$array["mail_membre"]?></td>
		</tr>
		<tr>
			<td><a href="./userpage.php?order=1">Voir commandes</a></td>
		</tr>
		<tr>
			<td><a href="./userpage.php?delete=1">Supprimer</a></td>
		</tr>
	</table><br />
	<?php

	if (isset($_GET["order"]))
	{
		$request2 = "
			SELECT * FROM commande
			INNER JOIN membre ON commande.id_membre = membre.id_membre
			WHERE membre.id_membre = $id;
		";
		?>
		<table>
		<thead><th>Date</th></thead>
		<?php
		$rep2 = mysqli_query($link, $request2);
		while ($array = mysqli_fetch_array($rep2))
		{
			echo("<tr><td>");
			echo($array["date_commande"]);
			echo("</td></tr>");
		}
		echo("</table>");
	}
	elseif (isset($_GET["delete"]))
	{
		?>
		<form action="./controller/userpage.php" method=POST>
			<p>Renseigner votre mot de passe pour supprimer:</p>
			<input type="password" name="pwd">
			<input type="submit" name="submit" value="Supprimer">
		</form>
		<?php
		if (isset($_GET["error"]))
			echo("<p>Erreur - Mot de passe incorrect</p>");
	}?>
</body>
</html>