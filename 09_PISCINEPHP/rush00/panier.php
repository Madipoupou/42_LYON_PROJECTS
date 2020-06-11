<?php

session_start();
include_once("./lib/panier.php");
include 'inc/header.php';
if (isset($_GET["nom"]) && isset($_GET["prix"]) && isset($_GET["prop"]))
{
    if (ft_create_basket())
        ft_add_organe($_GET["nom"], $_GET["prop"], $_GET["prix"]);
    header("refresh: 0.1; url=./panier.php");
}
if (isset($_GET["nom"]) && isset($_GET["prop"]) && isset($_GET["action"]))
{
    if (ft_count_basket() !== 0)
    {
        if ($_GET["action"] === "add1")
            ft_edit_qt($_GET["nom"], $_GET["prop"], 1);
        if ($_GET["action"] === "rem1")
            ft_edit_qt($_GET["nom"], $_GET["prop"], -1);
        header("refresh: 0.1; url=./panier.php");
    }
}
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Lifeshop: Panier</title>
</head>
<body>
<div class="body_container">
    <div class="basket_container">
        <div class="row">
            <div class="col text-center" style="padding-bottom: 3rem;">
                <div class="section_title catalogue_title">
                    <h2>Votre panier</h2>
                </div>
            </div>
        </div>
    <div class="container">
        <div class="row text-center">
            <div class="col">
                <h6>Nom de l'organe</h6>
            </div>
            <div class="col">
                <h6>Donneur</h6>
            </div>
            <div class="col">
                <h6>Quantité</h6>
            </div>
            <div class="col">
                <h6>Prix unitaire</h6>
            </div>
            <div class="col">
                <h6>Ajouter unité</h6>
            </div>
            <div class="col">
                <h6>Retirer unité</h6>
            </div>
        </div>
        
    <?php

    if (ft_create_basket())
    {
        $nb_articles = ft_count_basket();
		if ($nb_articles <= 0)
            echo "<tr><td colspan=\"6\">Votre panier est vide </ td></tr>";
		else
		{
			for ($i=0 ;$i < $nb_articles ; $i++)
			{
                echo '<div class="row text-center">';
				echo('<div style="margin: 0;" class="col align-items-center"><img width="25" height="25" src="./images/'.htmlspecialchars($_SESSION["panier"]["nom_organe"][$i]).'.png">'.htmlspecialchars($_SESSION["panier"]["nom_organe"][$i]).'</div>');
				echo('<div class="col">'.htmlspecialchars($_SESSION["panier"]["donneur"][$i])."</div>");
				echo('<div class="col">'.htmlspecialchars($_SESSION["panier"]["qt_organe"][$i])."</div>");
                echo('<div class="col">'.htmlspecialchars($_SESSION["panier"]["prix_organe"][$i])."€</div>");
                $temp = "action=add1&nom=".$_SESSION["panier"]["nom_organe"][$i]."&prop=".$_SESSION["panier"]["donneur"][$i];
				echo('<div class="col"><a style ="text-decoration: none;" class="product_price" href="'.htmlspecialchars("panier.php?".$temp)."\">+</a></div>");
                $temp = "action=rem1&nom=".$_SESSION["panier"]["nom_organe"][$i]."&prop=".$_SESSION["panier"]["donneur"][$i];
                echo('<div class="col"><a style ="text-decoration: none;" class="product_price" href="'.htmlspecialchars("panier.php?".$temp)."\">-</a></div>");
                echo '</div>';
            }
            echo "</div>";
            echo "<br>";
            echo '<div class="row">';
            echo('<h4>Votre total : <span style="color: #fe4c50;">'.ft_basket_amount().'€</span></h4>');
            echo("</div>");
            echo('<div class="col text-center"><div style="width:30%; margin: auto;" class="btn red_button text-light"><a href="./commander.php">Valider ma commande</a></div></div>');
		}
    }
    $tot = count($_SESSION["panier"])

    ?>
    </div>
</div>
</div>
</body>
</html>