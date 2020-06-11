<?php

/* Just echo an error and exit */
function ft_error()
{
	echo("ERROR\n");
	exit();
}

/* Returns true if $login is in $account */
function ft_is_login_stored($login, $accounts)
{
	foreach ($accounts as $account)
	{
		if ($account["login"] === $login)
			return (true);
	}
	return (false);
}


/*********************
 *       MAIN        *
*********************/
/* Check if the submit is correct */
if (!isset($_POST["submit"]) || $_POST["submit"] !== "OK")
	ft_error();

/* Check if login, oldpw and newpw are set */
if (!isset($_POST["login"]) || !isset($_POST["oldpw"]) || !isset($_POST["newpw"]))
	ft_error();

/* Check if login, oldpw and newpw are empty */
if ($_POST["login"] === "" || $_POST["oldpw"] === "" || $_POST["newpw"] === "")
	ft_error();

/* Store accounts from passwd file if accounts exist */
/* Check if account to add does not exist */
$accounts = file_get_contents("./../private/passwd");
if ($accounts === false)
	ft_error();
$accounts = unserialize($accounts);
if (!$accounts || !ft_is_login_stored($_POST["login"], $accounts))
	ft_error();
	
/* Check oldpw and set new */
$oldpw_hash = hash("whirlpool", $_POST["oldpw"]);
foreach ($accounts as $key => $account)
{
	if ($account["login"] === $_POST["login"])
	{
		if ($account["passwd"] !== $oldpw_hash)
			ft_error();
		$accounts[$key]["passwd"] = hash("whirlpool", $_POST["newpw"]);
		break ;
	}
}

/* Write new data to passwd file */
$ok = file_put_contents("./../private/passwd", serialize($accounts));
if ($ok === false)
	ft_error();
echo("OK\n");
header("Location: ./index.html");

?>
