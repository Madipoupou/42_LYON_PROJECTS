<?php

session_start();

/* Check if user already connected */
if (isset($_SESSION["user_log"]))
{
	header("refresh: 0.1; url=./index.php");
	exit();
}
else
{
	include 'inc/header.php';
?>
<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="UTF-8">
	<title>Lifeshop: Inscription</title>
</head>
<body>
<div class="body_container">
	<div class="register_container">
		<div class="row">
			<div class="col text-center">
				<div class="section_title catalogue_title">
					<h2>Créez votre compte</h2>
				</div>
			</div>
		</div>
		<div class="row align-items-center">
			<div class="col text-center">
				<div class="catalogue_sorting">
					<form action="./controller/register.php" method="POST">
						<?php
						if (isset($_GET["status"]))
						{
							if ($_GET["status"] === "mail_exists")
								echo('<div class="alert alert-danger">Adresse mail déjà existante.</div>');
							elseif ($_GET["status"] === "mail_error")
								echo('<div class="alert alert-danger">Adresse mail incorrecte.</div>');
							elseif ($_GET["status"] === "pwd_error")
								echo('<div class="alert alert-danger">Mot de passe incorrect (au moins six caractères).</div>');
							elseif ($_GET["status"] === "pwd_match")
								echo('<div class="alert alert-danger">Les mots de passe ne correspondent pas.</div>');
							elseif ($_GET["status"] === "empty")
								echo('<div class="alert alert-danger">Veuillez remplir tous les champs.</div>');
							elseif ($_GET["status"] === "tel")
								echo('<div class="alert alert-danger">Téléphone incorrect.</div>');
							elseif ($_GET["status"] === "stupid")
								echo('<div class="alert alert-danger">Veuillez remplir le formulaire correctement.</div>');
							elseif ($_GET["status"] === "db")
								echo('<div class="alert alert-danger">Erreur inattendue.</div>');
						}
						?>
							<div class="form-group">
								<label>Adresse email</label>
								<input class="form-control" type="email" name="mail" placeholder="Une addresse email" />
							</div>
							<div class="form-group">
								<label>Mot de passe</label>
								<input class="form-control" type="password" name="pwd1" placeholder="Entrez un mot de passe" />
							</div>
							<div class="form-group">
								<label>Confirmer le mot de passe</label>
								<input class="form-control" type="password" name="pwd2" placeholder="Encore une fois" />
							</div>
							<div class="form-group">
								<label>Nom</label>
								<input class="form-control" type="text" name="nom" />
							</div>
							<div class="form-group">
								<label>Prénom</label>
								<input class="form-control" type="text" name="prenom" />
							</div>
							<p>En créant votre compte vous acceptez nos <a href="#" style="color:dodgerblue">Conditions d'utilisation</a>.</p>
							<button type="submit" name="submit" class="btn red_button text-light">Envoyer</button>
					</form>
			</div>
		</div>
	</div>
</div>
</body>
</html>

<?php
}
include 'inc/footer.php';
?>
