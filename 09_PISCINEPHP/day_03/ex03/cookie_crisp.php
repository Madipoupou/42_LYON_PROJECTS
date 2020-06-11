<?php

if (!isset($_GET["action"]))
	exit();
if ($_GET["action"] !== "set" && $_GET["action"] !== "del" && $_GET["action"] !== "get")
	exit();
$action = $_GET["action"];
switch ($action)
{
	case "set":
	{
		if (!isset($_GET["name"]) || !isset($_GET["value"]))
			exit();
		setcookie($_GET["name"], $_GET["value"]);
		break ;
	}
	case "get":
	{
		if (!isset($_GET["name"]))
			exit();
		if (isset($_COOKIE[$_GET["name"]]))
			echo($_COOKIE[$_GET["name"]]."\n");
		break ;
	}
	case "del":
	{
		if (!isset($_GET["name"]))
			exit();
		setcookie($_GET["name"], "", time() - 3600);
		break ;
	}
}

?>
