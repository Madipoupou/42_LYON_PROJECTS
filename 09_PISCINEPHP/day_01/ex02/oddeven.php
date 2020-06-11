#!/usr/bin/php
<?PHP

$fd = fopen("php://stdin", "r");
while ($fd && (feof($fd) == FALSE))
{
	echo("Entrez un nombre: ");
	$str = fgets($fd);
	if ($str)
	{
		$str = trim($str, "\n");
		if (!is_numeric($str) || !is_int($str + 0))
			echo("'$str' n'est pas un chiffre\n");
		else
		{
			if ($str % 2 == 0)
				echo("Le chiffre $str est Pair\n");
			elseif ($str % 2 == 1 || $str % 2 == -1)
				echo("Le chiffre $str est Impair\n");
			else
				echo("'$str' n'est pas un chiffre\n");
		}
	}
}
echo("\n");

?>
