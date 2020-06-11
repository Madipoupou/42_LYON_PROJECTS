<?php

if (isset($_SERVER["PHP_AUTH_USER"]) && isset($_SERVER["PHP_AUTH_PW"]))
{
	$user = $_SERVER["PHP_AUTH_USER"];
	$pwd = $_SERVER["PHP_AUTH_PW"];
	if ($user === "zaz" && $pwd === "jaimelespetitsponeys")
	{
		$str_img = file_get_contents("../img/42.png");
		$str_img = base64_encode($str_img);
		echo(
			"<html><body>\n".
			"Bonjour Zaz<br />\n".
			"<img src='data:image/png:base64,".
			$str_img.
			"'>\n".
			"</body></html>\n"
		);
	}
	else
	{
		header("HTTP/1.0 401 Unauthorized");
		header("WWW-Authenticate: Basic realm=''Espace membres''");
		echo("<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n");
	}
}
else
{
	header("HTTP/1.0 401 Unauthorized");
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	echo("<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n");
}

?>
