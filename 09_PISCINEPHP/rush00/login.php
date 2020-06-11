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
		<title>Lifeshop: Connexion</title>
	</head>
	<body>
		<div class="body_container">
			<div class="login_container">
				<div class="row">
					<div class="col text-center">
						<div class="section_title catalogue_title">
							<h2>Connexion</h2>
						</div>
					</div>
				</div>
				<div class="row align-items-center">
					<div class="col text-center">
						<div class="catalogue_sorting">
							<form action="./controller/auth.php" method="POST">
								<?php
								if (isset($_GET["status"]))
								{
									if ($_GET["status"] === "mail")
										echo('<div class="alert alert-danger">Adresse mail incorrecte.</div>');
									elseif ($_GET["status"] === "pwd")
										echo('<div class="alert alert-danger"Mot de passe incorrect.</div>');
								}
								?>
								<div class="form-group">
									<label>Adresse email</label>
									<input type="email" name="mail" class="form-control" placeholder="Votre adresse email" />
								</div>
								<div class="form-group">
									<label>Password</label>
									<input type="password" name="pwd" class="form-control" placeholder="Votre mot de passe" />
								</div>
								<button type="submit" name="submit" class="btn red_button text-light">Connexion</button>
							</form>
						</div>
					</div>
				</div>
			</div>
		</div>
	</body>
	</html>

<?php
}
?>