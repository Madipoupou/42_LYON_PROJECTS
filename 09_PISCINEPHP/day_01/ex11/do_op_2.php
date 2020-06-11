#!/usr/bin/php
<?PHP

function is_digit($c)
{
	return ($c >= "0" && $c <= "9");
}

function is_op($c)
{
	return ($c == "+" || $c == "-" || $c == "*" || $c == "/" || $c == "%");
}

if ($argc != 2)
{
	echo("Incorrect Parameters\n");
	exit();
}
$str = trim($argv[1]);
$tab = str_split($str);;
$size = sizeof($tab);
if ($size < 3)
{
	echo("Syntax Error\n");
	exit();
}
$num1_str = "";
$num2_str = "";
$i = 0;
if ($tab[$i] == '-')
{
	$num1_str .= "-";
	$i++;
}
if (!is_digit($tab[$i]))
{
	echo("Syntax Error\n");
	exit();
}
while (true)
{
	if (is_digit($tab[$i]))
	{
		$num1_str .= $tab[$i];
		$i++;
	}
	else
		break ;
}
while ($tab[$i] == " ")
	$i++;
if (!is_op($tab[$i]))
{
	echo("Syntax Error\n");
	exit();
}
$op = $tab[$i];
$i++;
$str = substr($str, $i);
$str = trim($str);
$tab = str_split($str);;
$i = 0;
if ($tab[$i] == '-')
{
	$num2_str .= "-";
	$i++;
}
if (!is_digit($tab[$i]))
{
	echo("Syntax Error\n");
	exit();
}
while (true)
{
	if (is_digit($tab[$i]))
	{
		$num2_str .= $tab[$i];
		$i++;
	}
	else
		break ;
}
if ($i != sizeof($tab))
{
	echo("Syntax Error\n");
	exit();
}
$res = "";
$op1 = intval($num1_str);
$op2 = intval($num2_str);
if ("$op" == "+")
		$res = $op1 + $op2;
	elseif ("$op" == "-")
		$res = $op1 - $op2;
	elseif ("$op" == "*")
		$res = $op1 * $op2;
	elseif ("$op" == "/")
		$res = $op1 / $op2;
	elseif ("$op" == "%")
		$res = $op1 % $op2;
	echo("$res\n");

?>
