#!/usr/bin/php
<?PHP

if ($argc == 2)
{
	$tab = array_filter(explode(" ", $argv[1]), "strlen");
	$str = "";
	foreach($tab as $elem)
		$str .= $elem." ";
	$str = trim($str, " ");
	echo("$str\n");
}

?>
