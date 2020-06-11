<?php

include("./auth.php");
session_start();

/* Sets a session variable to "", displays error */
function ft_error()
{
	$_SESSION["loggued_on_user"] = "";
	echo("ERROR\n");
	exit();
}


/********************
*       MAIN        *
********************/
/* Checks if $_GET is well set */
if (!isset($_GET["login"]) || !isset($_GET["passwd"]))
	ft_error();

/* Check if $_GET are empty */
if ($_GET["login"] == "" || $_GET["passwd"] == "")
	ft_error();

/* Check if login/passwd are OK */
if (!auth($_GET["login"], $_GET["passwd"]))
	ft_error();
$_SESSION["loggued_on_user"] = $_GET["login"];
echo("OK\n");

?>
