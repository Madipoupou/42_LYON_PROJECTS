#!/usr/bin/php
<?PHP

if ($argc != 4)
	echo("Incorrect Parameters\n");
else
{
	$op1 = intval($argv[1]);
	$op2 = trim($argv[2]);
	$op3 = intval($argv[3]);
	if ("$op2" == "+")
		$res = $op1 + $op3;
	elseif ("$op2" == "-")
		$res = $op1 - $op3;
	elseif ("$op2" == "*")
		$res = $op1 * $op3;
	elseif ("$op2" == "/")
		$res = $op1 / $op3;
	elseif ("$op2" == "%")
		$res = $op1 % $op3;
	echo("$res\n");
}

?>
