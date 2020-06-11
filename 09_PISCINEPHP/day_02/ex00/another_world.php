#!/usr/bin/php
<?PHP

if ($argc < 2)
	exit();
$str = trim(preg_replace("/[ \t\r]+/", " ", $argv[1]))."\n";
echo($str);

?>
