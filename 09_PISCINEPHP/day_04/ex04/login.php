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

if (!isset($_SESSION["loggued_on_user"]) || $_SESSION["loggued_on_user"] === "")
{
	/* Checks if $_POST is well set */
	if (!isset($_POST["login"]) || !isset($_POST["passwd"]))
		ft_error();

	/* Check if $_POST are empty */
	if ($_POST["login"] == "" || $_POST["passwd"] == "")
		ft_error();

	/* Check if login/passwd are OK */
	if (!auth($_POST["login"], $_POST["passwd"]))
		ft_error();
	$_SESSION["loggued_on_user"] = $_POST["login"];
}
else
{
	/* Checks if $_POST is well set */
	if (isset($_POST["login"]) && isset($_POST["passwd"]) && $_POST["login"] !== "" && $_POST["passwd"] !== "")
	{
	   if (!auth($_POST["login"], $_POST["passwd"]))
	   {
		   $_SESSION["loggued_on_user"] = "";
		   ft_error();
	   }
	}
}

?>
<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="UTF-8">
	<title>CHAT</title>
</head>
<body>
	<div align="center">
		<iframe name="chat" src="./chat.php" width="60%" height="550px" frameborder="1"></iframe>
		<iframe name="speak" src="./speak.php" width="60%" height="50px" frameborder="1"></iframe>
	</div>
</body>
</html>
