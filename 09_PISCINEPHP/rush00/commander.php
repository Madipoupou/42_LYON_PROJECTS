<?php

session_start();
include_once("./lib/panier.php");

$nb_articles = ft_count_basket();
if ($nb_articles <= 0)
    header("Location: ./panier.php");

?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Lifeshop: Commander</title>
</head>
<body>
    <h2>Votre commande:</h2>
    <table>
        <thead>
        <th>Nom de l'organe</th>
        <th>Donneur</th>
        <th>Quantité</th>
        <th>Prix unitaire</th>
        </thead>
    <?php
    for ($i=0 ;$i < $nb_articles ; $i++)
    {
        echo("<tr>");
        echo("<td>".htmlspecialchars($_SESSION["panier"]["nom_organe"][$i])."</ td>");
        echo("<td>".htmlspecialchars($_SESSION["panier"]["donneur"][$i])."</ td>");
        echo("<td>".htmlspecialchars($_SESSION["panier"]["qt_organe"][$i])."</td>");
        echo("<td>".htmlspecialchars($_SESSION["panier"]["prix_organe"][$i])."</ td>");
        echo("</tr>");
    }
    echo("<tr><td colspan=\"4\">");
    echo("Total : ".ft_basket_amount());
    echo("</table>");
    echo("</td></tr>");
    $tot = count($_SESSION["panier"]);
    echo("<br /><br />");
    ?>
    <h2>Vos coordonnées:</h2>
    <form action="./controller/commander.php" method="POST">
    <p>Addresse de livraison:</p>
    <input type="text" name="add" /><br />
    <p>Numéro de carte bancaire:</p>
    <input type="text" name="cb" /><br />
    <p>Date d'expiration:</p>
    <input type="date" name="date" /><br />
    <p>Cryptogramme visuel:</p>
    <input type="text" name="crypt" /><br /><br />
    <?php
    if (isset($_GET["error"]))
    {
        if ($_GET["error"] === "empty")
            echo("<p>Erreur - Tous les champs doivent être renseignés.</p>");
        elseif ($_GET["error"] === "add")
            echo("<p>Erreur - Adresse incorrecte.</p>");
        elseif ($_GET["error"] === "cb")
            echo("<p>Erreur - Numéro de carte invalide.</p>");
        elseif ($_GET["error"] === "crypt")
            echo("<p>Erreur - Cryptogramme invalide.</p>");
        elseif ($_GET["error"] === "db")
            echo("<p>Erreur - Impossible de passer commande.</p>");
        elseif ($_GET["error"] === "date")
            echo("<p>Erreur - La date n'est pas valide.</p>");
    }
    ?>
    <input type="submit" name="submit" value="Commander" />
    
    </form>

</body>
</html>