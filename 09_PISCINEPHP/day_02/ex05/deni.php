#!/usr/bin/php
<?PHP

// Test on argc and argv[1]
if ($argc < 3 || !file_exists($argv[1]))
	exit();
$fd = fopen($argv[1], "r");

// Create an array of the csv keys and test if argv[2] is a key
$first_line = fgets($fd);
$keys0 = explode(";", $first_line);
foreach ($keys0 as $elem)
	$keys[] = trim($elem);
$pos = array_search($argv[2], $keys);
if ($pos === false)
{
	fclose($fd);
	exit();
}

// Array of CSV content
while (($temp = fgetcsv($fd, 0, ";")) !== false)
	$array_csv[] = $temp;
fclose($fd);

// Arrays according to keys
$i = 0;
foreach ($keys as $key)
{
	$temp = array();
	foreach ($array_csv as $elem)
		$temp[$elem[$pos]] = $elem[$i];
	$$key = $temp;
	$i++;
}

// Command exec
$stdin = fopen("php://stdin", "r");
while (!feof($stdin))
{
	echo("Entrez votre commande: ");
	$command = fgets($stdin);
	if ($command)
		eval($command);
}
fclose($stdin);
echo("\n");

?>
