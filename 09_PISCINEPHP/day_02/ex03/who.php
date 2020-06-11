#!/usr/bin/php
<?PHP

date_default_timezone_set("Europe/Paris");
$fd = fopen("/var/run/utmpx", "r");
$tab = array();
while ($temp = fread($fd, 628))
{
	$ext = unpack("a256a/a4b/a32c/id/ie/I2f/a256g/i16h", $temp);
	$tab[] = $ext;
}
fclose($fd);
$res = array();
foreach ($tab as $elem)
{
	if ($elem["e"] == "7")
		$res[] = $elem;
}
$tab = array();
foreach ($res as $elem)
{
	$name = $elem["a"];
	$proc = $elem["c"];
	$date = date("M d H:i", $elem["f1"]);
	$tab[] = array($name, $proc, $date);
}
foreach ($tab as $elem)
	echo($elem[0]." ".$elem[1]."  ".$elem[2]."\n");

?>
