<?php

session_start();
date_default_timezone_set('Europe/Paris');

/* Just echo an error and exit */
function ft_error()
{
	echo("ERROR\n");
	exit();
}


/********************
*       MAIN        *
********************/
/* Check session var */
if (!isset($_SESSION["loggued_on_user"]) || $_SESSION["loggued_on_user"] === "")
	ft_error();

/* Check "private" exists */
if (!file_exists("./../private"))
{
	$ok = mkdir("./../private");
	if ($ok === false)
		ft_error();
}

/* Check chat file exists */
if (!file_exists("./../private/chat"))
{
	$ok = file_put_contents("./../private/chat", null);
	if ($ok === false)
		ft_error();
}

/* Read chat file */
$messages = file_get_contents("./../private/chat");
$messages = unserialize($messages);
if ($messages)
{
	foreach ($messages as $message)
		echo("<p>".date("H:i - ", $message["time"])."<b>".$message["login"]."</b>: ".$message["msg"]."<br />");
}

?>
