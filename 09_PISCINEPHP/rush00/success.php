<?php

session_start();
require_once("./lib/panier.php");
ft_rem_basket();

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Lifeshop: Commande validée</title>
</head>
<body>
    <p>Votre commande a été validée. Félicitations.</p>
    <a href="./index.php">Retour Accueil</a>
</body>
</html>