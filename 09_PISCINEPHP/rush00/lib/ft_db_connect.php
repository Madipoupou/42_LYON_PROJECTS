<?php

/* Connects to DB as root, returns connection var if ok, NULL else */
function ft_db_connect($name)
{
	$username = "root";
	$passwd = "";
	$host = "127.0.0.1";
	if ($name === "")
		$link = mysqli_connect($host, $username, $passwd);
	else
		$link = mysqli_connect($host, $username, $passwd, $name);
	if (mysqli_connect_errno($link))
	{
		echo("Erreur - Connexion à la base de données impossible\n");
		return (NULL);
	}
	return ($link);
}

?>
