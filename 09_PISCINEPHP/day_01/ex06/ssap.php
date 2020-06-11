#!/usr/bin/php
<?PHP

$i = 1;
$tab = array();
while ($i < $argc)
{
	$temp = array_filter(explode(" ", $argv[$i]), "strlen");
	$tab = array_merge($tab, $temp);
	$i++;
}
sort($tab);
foreach($tab as $elem)
	echo("$elem\n");

?>
