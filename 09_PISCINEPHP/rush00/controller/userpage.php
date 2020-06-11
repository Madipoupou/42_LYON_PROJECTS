<?php

session_start();
require_once("./../lib/ft_db_connect.php");
if (isset($_POST["pwd"]))
{
    $pwd = hash("whirlpool", $_POST["pwd"]);
    $id = $_SESSION["id_log"];
	$link = ft_db_connect("lifeshop");
	$request = "SELECT pwd_membre FROM membre WHERE id_membre = $id;";
	$rep = mysqli_query($link, $request);
    if ($rep === false)
        header("refresh: 0.1; url=./../userpage.php?delete=1&error=1");
	$rep = mysqli_fetch_array($rep);
	if ($rep["pwd_membre"] !== $pwd)
        header("refresh: 0.1; url=./../userpage.php?delete=1&error=1");
    $request = "DELETE FROM commande WHERE id_membre = $id;";
	$rep = mysqli_query($link, $request);
    $request = "DELETE FROM membre WHERE id_membre = $id;";
	$rep = mysqli_query($link, $request);
	header("refresh: 0.1; url=./../controller/logout.php");
}
else
	header("refresh: 0.1; url=./../userpage.php?delete=1&error=1");

?>