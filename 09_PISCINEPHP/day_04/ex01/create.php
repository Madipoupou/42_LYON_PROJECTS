<?php

/* Just echo an error and exit */
function ft_error()
{
	echo("ERROR\n");
	exit();
}


/*********************
 *       MAIN        *
*********************/
/* Check if the submit is correct */
if (!isset($_POST["submit"]) || $_POST["submit"] !== "OK")
	ft_error();

/* Check if login and passwd are set */
if (!isset($_POST["login"]) || !isset($_POST["passwd"]))
	ft_error();

/* Check if login and passwd are empty */
if ($_POST["login"] === "" || $_POST["passwd"] === "")
	ft_error();

/* Folder creation if necessary */
if (!file_exists("./../private/"))
{
	$ok = mkdir("./../private/");
	if ($ok === false)
		ft_error();
}

/* File creation if necessary */
if (!file_exists("./../private/passwd"))
{
	$ok = file_put_contents("./../private/passwd", null);
	if ($ok === false)
		ft_error();
}

/* Store accounts from passwd file if accounts exist */
/* Check if account to add already exists */
$accounts = file_get_contents("./../private/passwd");
$accounts = unserialize($accounts);
if ($accounts)
{
	foreach ($accounts as $account)
	{
		if ($account["login"] === $_POST["login"])
			ft_error();
	}
}

/* Append the new user to the passwd file */
$new_user["login"] = $_POST["login"];
$new_user["passwd"] = hash("whirlpool", $_POST["passwd"]);
$accounts[] = $new_user;
file_put_contents("./../private/passwd", serialize($accounts));
echo("OK\n");

?>
