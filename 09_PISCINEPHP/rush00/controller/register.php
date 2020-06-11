<?php

session_start();
require_once("../lib/ft_db_connect.php");

/* Sends back to inscription with error passed with $_GET */
function ft_send_back($error)
{
	header("refresh: 0.1; url=./../register.php?status=$error");
	exit();	
}

/* Check if values are set */
if (!isset($_POST["mail"]) || !isset($_POST["pwd1"]) || !isset($_POST["pwd2"]) || !isset($_POST["nom"]) ||
	!isset($_POST["prenom"]))
	ft_send_back("empty");
if ($_POST["mail"] === "" || $_POST["pwd1"] === "" || $_POST["pwd2"] === "" || $_POST["nom"] === "" ||
	$_POST["prenom"] === "")
	ft_send_back("empty");

/* Set variables */
$mail = $_POST["mail"];
$pwd1 = $_POST["pwd1"];
$pwd2 = $_POST["pwd2"];
$nom = $_POST["nom"];
$prenom = $_POST["prenom"];
if (isset($_POST["add"]) && $_POST["add"] !== "")
	$add = $_POST["add"];
else
	$add = "";
if (isset($_POST["tel"]) && $_POST["tel"] !== "")
	$tel = $_POST["tel"];
else
	$tel = "0000000000";

/* Test mail */
if (!filter_var($mail, FILTER_VALIDATE_EMAIL))
	ft_send_back("mail_error");

/* Check pwd identiques et longueur pwd */
if ($pwd1 !== $pwd2)
	ft_send_back("pwd_match");
if (strlen($pwd1) < 6)
	ft_send_back("pwd_error");
$pwd1 = hash("whirlpool", $pwd1);

/* Check len of the strings */
if (strlen($tel) != 10 || !is_numeric($tel))
	ft_send_back("tel");
if (strlen($nom) >= 30 || strlen($prenom) >= 30 || strlen($add) >= 100)
	ft_send_back("stupid");

/* DB connexion and check if user already exists */
$link = ft_db_connect("lifeshop");
if ($link == NULL)
	ft_send_back("db");
$request = "SELECT * FROM membre WHERE mail_membre = '$mail';";
$rep = mysqli_query($link, $request);
$num_row = mysqli_num_rows($rep);
if ($num_row !== 0)
	ft_send_back("mail_exists");

/* Insert into membre table the new user */
$request = "INSERT INTO membre
				(nom_membre, prenom_membre, mail_membre, adresse_membre, tel_membre, pwd_membre)
			VALUES
				('$nom', '$prenom', '$mail', '$add', '$tel', '$pwd1');";
$rep = mysqli_query($link, $request);
if ($rep === false)
	ft_send_back("db");
$_SESSION["user_log"] = utf8_encode($rep["prenom_membre"]);
$_SESSION["id_log"] = $rep["id_membre"];
$_SESSION["user_type"] = utf8_encode($rep["id_membrecat"]);
header("refresh: 0.1; url=./../index.php");

?>
