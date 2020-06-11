#!/usr/bin/php
<?PHP

if ($argc > 2)
{
	$ref = $argv[1];
	$res = array();
	for ($i = 2; $i < $argc; $i++)
	{
		$tab = explode(":", $argv[$i]);
		$key = $tab[0];
		$val = $tab[1];
		$res["$key"] = "$val";
	}
	if (array_key_exists($ref, $res))
		echo($res[$ref] . "\n");
}

?>
