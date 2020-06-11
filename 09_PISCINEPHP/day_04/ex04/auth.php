<?php

/* Checks if $login:$passwd is valid in "./../private/passwd" */
function auth($login, $passwd)
{
	if (!$login || !$passwd)
		return (false);
	$accounts = file_get_contents("./../private/passwd");
	if ($accounts === false)
		return (false);
	$accounts = unserialize($accounts);
	$passwd_hash = hash("whirlpool", $passwd);
	foreach ($accounts as $account)
	{
		if ($account["login"] === $login)
		{
			if ($account["passwd"] === $passwd_hash)
				return (true);
			return (false);
		}
	}
	return (false);
}

?>
