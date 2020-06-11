<?php

require_once("lib/ft_db_connect.php");
session_start();
/* If user is not authorized */
if (!isset($_SESSION["user_type"]) || $_SESSION["user_type"] != 1)
	header("Location: ./index.php");

/* Display according to $_GET status */
if (isset($_GET["type"]))
{
	if ($_GET["type"] === "organe")
	{
		/* Tableau d'édition des organes */
		$link = ft_db_connect("lifeshop");
		$request = 
			"SELECT organe.id_organe, organe.prix_organe, organe.qualite_organe, categorie_organe.nom_orgcat, proprietaire.login_prop
			FROM organe
			INNER JOIN categorie_organe ON organe.id_orgcat = categorie_organe.id_orgcat
			INNER JOIN proprietaire ON organe.id_prop = proprietaire.id_prop
			ORDER BY id_organe ASC;";
		$rep = mysqli_query($link, $request);
		$num_row = mysqli_num_rows($rep);
		if ($num_row > 0)
		{
			echo("<h2>Liste des organes:</h2>");
			echo("<table>");
			echo("<thead><tr><th>Référence</th><th>Prix</th><th>Qualité</th><th>Catégorie</th><th>Propriétaire</th></thead>");
			while ($tab = mysqli_fetch_array($rep))
			{
				echo(
					"<tr>".
					"<td>".htmlspecialchars(utf8_encode($tab["id_organe"]))."</td>".
					"<td>".(float)htmlspecialchars(utf8_encode($tab["prix_organe"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["qualite_organe"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["nom_orgcat"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["login_prop"]))."</td>".
					"</tr>"
				);
			}
			echo("</table>");
		}
		?>
		<br />
		<h3>Ajouter un organe:</h3>

		<table>
		<thead><th>Catégorie</th><th>Prix</th><th>Donneur</th><th>Qualité</th><th></th></thead>
		<form action="./controller/admin.php?type=organe" method="POST">
		<tr>
			<td><input type="text" name="cat"></td>
			<td><input type="text" name="prix"></td>
			<td><input type="text" name="prop"></td>
			<td><input type="text" name="qualite"></td>
			<td><input type="submit" name="submit" value="OK"></td>
		</tr>
		<?php
			if (isset($_GET["error"]))
				echo("<tr><td colspan=5>Erreur lors de l'ajout de données.</td></tr>");
		?>
		</form>
		</table>
		<?php
		echo("</table>");
	}
	elseif ($_GET["type"] === "prop")
	{
		/* Tableau d'édition des propriétaires */
		$link = ft_db_connect("lifeshop");
		$request = "SELECT * FROM proprietaire ORDER BY id_prop ASC;";
		$rep = mysqli_query($link, $request);
		$num_row = mysqli_num_rows($rep);
		if ($num_row > 0)
		{
			echo("<h2>Liste des donneurs:</h2>");
			echo("<table>");
			echo("<thead><tr><th>Référence</th><th>Nom</th><th>Prénom</th><th>Age</th><th>Login</th></thead>");
			while ($tab = mysqli_fetch_array($rep))
			{
				echo(
					"<tr>".
					"<td>".htmlspecialchars(utf8_encode($tab["id_prop"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["nom_prop"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["prenom_prop"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["age_prop"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["login_prop"]))."</td>".
					"</tr>"
				);
			}
			echo("</table>");
		}
		?>
		<br />
		<h3>Ajouter un donneur:</h3>

		<table>
		<thead><th>Nom</th><th>Prénom</th><th>Age</th><th>Login</th><th></th></thead>
		<form action="./controller/admin.php?type=prop" method="POST">
		<tr>
			<td><input type="text" name="nom"></td>
			<td><input type="text" name="prenom"></td>
			<td><input type="text" name="age"></td>
			<td><input type="text" name="login"></td>
			<td><input type="submit" name="submit" value="OK"></td>
		</tr>
		<?php
			if (isset($_GET["error"]))
				echo("<tr><td colspan=5>Erreur lors de l'ajout de données.</td></tr>");
		?>
		</form>
		</table>
		<?php
	}
	elseif ($_GET["type"] === "cat")
	{
		/* Tableau d'édition des catégories */
		$link = ft_db_connect("lifeshop");
		$request = "SELECT * FROM categorie_organe ORDER BY id_orgcat ASC;";
		$rep = mysqli_query($link, $request);
		$num_row = mysqli_num_rows($rep);
		if ($num_row > 0)
		{
			echo("<h2>Liste des catégories:</h2>");
			echo("<table>");
			echo("<thead><tr><th>Référence</th><th>Nom catégorie</th></thead>");
			while ($tab = mysqli_fetch_array($rep))
			{
				echo(
					"<tr>".
					"<td>".htmlspecialchars(utf8_encode($tab["id_orgcat"]))."</td>".
					"<td>".htmlspecialchars(utf8_encode($tab["nom_orgcat"]))."</td>".
					"</tr>"
				);
			}
			echo("</table>");
		}
		?>
		<br />
		<h3>Ajouter une catégorie:</h3>
		<table>
		<thead><th>Nom</th><th></th></thead>
		<form action="./controller/admin.php?type=cat" method="POST">
		<tr>
			<td><input type="text" name="nom"></td>
			<td><input type="submit" name="submit" value="OK"></td>
		</tr>
		<?php
			if (isset($_GET["error"]))
				echo("<tr><td colspan=5>Erreur lors de l'ajout de données.</td></tr>");
		?>
		</form>
		</table>
		<?php
	}
	echo("<br />");
}
/* Formulaire de choix de l'admin */
?>
<form action="./admin.php" method="GET">
	<h3>Choisissez les données à éditer:</h3>
	<input id="organe" type="radio" name="type" value="organe">
	<label for="organe">Organes</label><br />
	<input id="prop" type="radio" name="type" value="prop">
	<label for="prop">Donneurs d'organes</label><br />
	<input id="cat" type="radio" name="type" value="cat">
	<label for="cat">Catégories d'organes</label><br /><br />
	<input type="submit" name="submit" value="OK">
</form>