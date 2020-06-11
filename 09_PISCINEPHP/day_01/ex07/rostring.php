#!/usr/bin/php
<?PHP

if ($argc > 1)
{
	$tab = array_filter(explode(" ", $argv[1]), "strlen");
	$size = sizeof($tab);
	if ($size > 1)
	{
		$temp = $tab[0];
		for ($i = 0; $i < $size - 1; $i++)
			$tab[$i] = $tab[$i + 1];
		$tab[$size - 1] = $temp;
	}
	$str = "";
	foreach($tab as $elem)
		$str .= "$elem ";
	$str = trim($str);
	echo("$str\n");
}

?>
