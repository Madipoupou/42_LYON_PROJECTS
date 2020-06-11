<?php

session_start();
require_once("../lib/ft_db_connect.php");

/* Sends back to inscription with error passed with $_GET */
function ft_send_back($error)
{
	header("refresh: 0.1; url=./../commander.php?error=$error");
	exit();	
}

/* Check if values are set */
if (!isset($_POST["add"]) || !isset($_POST["cb"]) || !isset($_POST["date"]) || !isset($_POST["crypt"]))
	ft_send_back("empty");
if ($_POST["add"] === "" || $_POST["cb"] === "" || $_POST["date"] === "" || $_POST["crypt"] === "")
	ft_send_back("empty");

/* Set variables */
$add = $_POST["add"];
$cb = $_POST["cb"];
$date = $_POST["date"];
$crypt = $_POST["crypt"];

/* Test add */
if (strlen($add) <= 5 || strlen($add) > 50)
	ft_send_back("add");

/* Check len of the strings */
if (strlen($cb) != 16 || !is_numeric($cb))
	ft_send_back("cb");
if (strlen($crypt) != 3 || !is_numeric($crypt))
	ft_send_back("crypt");
$phpdate = date("Y-m-d");
if (!strtotime($date) || $phpdate > $date)
	ft_send_back("date");

/* DB connexion and insert command */
$link = ft_db_connect("lifeshop");
if ($link == NULL)
    ft_send_back("db");
$id = $_SESSION["id_log"];
$request =
    "INSERT INTO commande
		(date_commande, id_membre)
	VALUES
        (now(), '$id');";
$rep = mysqli_query($link, $request);
if ($rep === false)
	ft_send_back("db");
header("refresh: 0.1; url=./../success.php");

?>