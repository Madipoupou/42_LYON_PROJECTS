<?php

session_start();

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
/* Check msg in $_POST AND SAVE IN "./../private/chat */
if (isset($_POST["msg"]))
{
	if (!file_exists("./../private"))
	{
		$ok = mkdir("./../private");
		if ($ok === false)
			ft_error();
	}
	if (!file_exists("./../private/chat"))
	{
		$ok = file_put_contents("./../private/chat", null);
		if ($ok === false)
			ft_error();
	}
	$chat = unserialize(file_get_contents("./../private/chat"));
	$fd = fopen("./../private/chat", "w");
	flock($fd, LOCK_EX);
	$temp["login"] = $_SESSION["loggued_on_user"];
	$temp["time"] = time();
	$temp["msg"] = $_POST["msg"];
	$chat[] = $temp;
	$ok = file_put_contents('../private/chat', serialize($chat));
	if ($ok === false)
		ft_error();
	fclose($fd);
}

?>
<!DOCTYPE html>
<html lang="fr">
<head>
	<meta charset="UTF-8">
	<title>SPEAK</title>
	<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
</head>
<body>
	<form action="speak.php" method="POST">
		<input type="text" name="msg" value=""/>
		<input type="submit" name="submit" value="Send"/>
	</form>

</body>
</html>
