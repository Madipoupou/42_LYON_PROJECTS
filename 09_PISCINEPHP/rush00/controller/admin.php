<?php

session_start();
require_once("../lib/ft_db_connect.php");

/* Sends back to inscription with error passed with $_GET */
function ft_send_back($type)
{
	header("refresh: 0.1; url=./../admin.php?type=$type&error=true");
	exit();	
}

/* Check if values are set */
if (!isset($_GET["type"]) || ($_GET["type"] !== "organe" && $_GET["type"] !== "prop" && $_GET["type"] !== "cat"))
    ft_send_back("");

$type = $_GET["type"];
$link = ft_db_connect("lifeshop");
switch ($type)
{
    case ("cat"):
    {
        /* Check set */
        if (!isset($_POST["nom"]))
            ft_send_back($type);
        
        /* Set var */
        $nom = utf8_decode(strtolower($_POST["nom"]));

        /* Check if var ok */
        if (strlen($nom) > 20)
            ft_send_back($type);
        $request = "SELECT * FROM categorie_organe";
        $rep = mysqli_query($link, $request);
        $id_cat = 0;
        while ($tab = mysqli_fetch_array($rep))
        {
            if ($tab["nom_orgcat"] === $nom)
            {
                $id_cat = $tab["id_orgcat"];
                break ;
            }
        }
        if ($id_cat)
            ft_send_back($type);       
        $request = "
            INSERT INTO categorie_organe (nom_orgcat)
            VALUES ('$nom');";
        $rep = mysqli_query($link, $request);
        if ($rep === false)
            ft_send_back($type);
        break ;
    }
    case ("prop"):
    {
        /* Check set */
        if (!isset($_POST["nom"]) || !isset($_POST["prenom"]) || !isset($_POST["age"]) || !isset($_POST["login"]))
            ft_send_back($type);
        
        /* Set var */
        $nom = utf8_decode($_POST["nom"]);
        $prenom = utf8_decode($_POST["prenom"]);
        $age = $_POST["age"];
        $login = utf8_decode($_POST["login"]);

        /* Check if var ok */
        if (!is_numeric($age))
            ft_send_back($type);
        if (strlen($nom) > 20)
            ft_send_back($type);
        if (strlen($prenom) > 20)
            ft_send_back($type);
        $request = "SELECT * FROM proprietaire";
        $rep = mysqli_query($link, $request);
        $id_prop = 0;
        while ($tab = mysqli_fetch_array($rep))
        {
            if ($tab["login_prop"] === $login)
            {
                $id_prop = $tab["id_prop"];
                break ;
            }
        }
        if ($id_prop)
            ft_send_back($type);
        $request = "
            INSERT INTO proprietaire (nom_prop, prenom_prop, login_prop, age_prop)
            VALUES ('$nom', '$prenom', '$login', '$age');";
        $rep = mysqli_query($link, $request);
        if ($rep === false)
            ft_send_back($type);
        break ;
    }
    case ("organe"):
    {
        /* Check set */
        if (!isset($_POST["cat"]) || !isset($_POST["prix"]) || !isset($_POST["prop"]) || !isset($_POST["qualite"]))
            ft_send_back($type);
        
        /* Set var */
        $cat = utf8_decode($_POST["cat"]);
        $prix = $_POST["prix"];
        $prop = utf8_decode($_POST["prop"]);
        $qualite = utf8_decode($_POST["qualite"]);

        /* Check if var ok */
        if (!is_numeric($prix))
            ft_send_back($type);
        if (strlen($qualite) > 10)
            ft_send_back($type);
        $request = "SELECT * FROM categorie_organe";
        $rep = mysqli_query($link, $request);
        $id_cat = 0;
        while ($tab = mysqli_fetch_array($rep))
        {
            if ($tab["nom_orgcat"] === $cat)
            {
                $id_cat = $tab["id_orgcat"];
                break ;
            }
        }
        if (!$id_cat)
            ft_send_back($type);
        $request = "SELECT * FROM proprietaire";
        $rep = mysqli_query($link, $request);
        $id_prop = 0;
        while ($tab = mysqli_fetch_array($rep))
        {
            if ($tab["login_prop"] === $prop)
            {
                $id_prop = $tab["id_prop"];
                break ;
            }
        }
        if (!$id_prop)
            ft_send_back($type);
        $request = "
            INSERT INTO organe (prix_organe, qualite_organe, id_orgcat, id_prop)
            VALUES ('$prix', '$qualite', '$id_cat', '$id_prop');";
        $rep = mysqli_query($link, $request);
        if ($rep === false)
            ft_send_back($type);
        break ;
    }
}
header("refresh: 0.1; url=./../admin.php?type=$type");

?>