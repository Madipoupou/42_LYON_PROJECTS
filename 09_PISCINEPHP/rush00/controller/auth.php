<?php

session_start();
require_once("../lib/ft_db_connect.php");

/* Check if mail and password are ok */
if (isset($_POST["mail"]) && isset($_POST["pwd"]))
{
	$mail = $_POST["mail"];
	$pwd = hash("whirlpool", $_POST["pwd"]);
	$link = ft_db_connect("lifeshop");
	$request = "SELECT * FROM membre WHERE mail_membre = '$mail';";
	$rep = mysqli_query($link, $request);
	if ($rep === false)
	{
		echo("Erreur - Demande rejetée\n");
		exit();
	}
	$num_row = mysqli_num_rows($rep);
	if ($num_row === 0)
	{
		header("refresh: 0.1; url=./../login.php?status=mail");
		exit();
	}
	$rep = mysqli_fetch_array($rep);
	if ($rep["pwd_membre"] !== $pwd)
	{
		header("refresh: 0.1; url=./../login.php?status=pwd");
		exit();
	}
	$_SESSION["user_log"] = utf8_encode($rep["prenom_membre"]);
	$_SESSION["id_log"] = utf8_encode($rep["id_membre"]);
	$_SESSION["user_type"] = utf8_encode($rep["id_membrecat"]);
	header("refresh: 0.1; url=./../index.php");
}

?>
