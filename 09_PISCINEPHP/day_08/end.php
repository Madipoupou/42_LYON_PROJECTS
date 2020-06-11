<?php

session_start();
if (!isset($_SESSION["gagnant"]))
    header("Location : ./index.php");

$gagnant = $_SESSION["gagnant"];
session_destroy();

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <title>Document</title>
</head>
<body>
    <p>Le joueur <?= $gagnant ?> a gagné!</p>
    <a href="./index.html">Retour à l'accueil.</a>
</body>
</html>