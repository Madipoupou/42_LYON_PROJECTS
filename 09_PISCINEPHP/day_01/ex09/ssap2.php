#!/usr/bin/php
<?PHP

function is_digit($a)
{
	if ("$a" >= "0" && "$a" <= "9")
		return (TRUE);
	return (FALSE);
}

function is_letter($a)
{
	if ("$a" >= "a" && "$a" <= "z")
		return (TRUE);
	return (FALSE);
}

function is_other($a)
{
	if (!is_letter($a) && !is_digit($a))
		return (TRUE);
	return (FALSE);
}

function is_sorted($str1, $str2)
{
	$str1 = strtolower($str1);
	$str2 = strtolower($str2);
	$tab1 = str_split($str1);
	$tab2 = str_split($str2);
	$size1 = sizeof($tab1);
	$size2 = sizeof($tab2);
	$i = 0;
	while ($i < $size1 && $i < $size2)
	{
		$c1 = $tab1[$i];
		$c2 = $tab2[$i];
		if ($c1 == $c2)
		{
			$i++;
			continue ;
		}
		if ((is_letter($c1) && is_letter($c2)) || (is_digit($c1) && is_digit($c2)) || (is_other($c1) && is_other($c2)))
		{
			if ($c1 < $c2)
				return (-1);
			else
				return (1);
		}
		else
		{
			if (is_letter($c1))
				return (-1);
			elseif (is_digit($c1) && is_letter($c2))
				return (1);
			elseif (is_digit($c1))
				return (-1);
			else
				return (1);
		}
		$i++;
	}
	if ($size1 == $size2)
		return (0);
	elseif ($i == $size1)
		return (-1);
	return (1);
}

function my_sort($tab_i)
{
	$tab = $tab_i;
	$size = sizeof($tab);
	for ($i = 0; $i < $size - 1; $i++)
	{
		for ($j = $i + 1; $j < $size; $j++)
		{
			if (is_sorted($tab[$i], $tab[$j]) == 1)
			{
				$temp = $tab[$i];
				$tab[$i] = $tab[$j];
				$tab[$j] = $temp;
			}
		}
	}
	return ($tab);
}

$i = 1;
$tab = array();
while ($i < $argc)
{
	$temp = array_filter(explode(" ", $argv[$i]), "strlen");
	$tab = array_merge($tab, $temp);
	$i++;
}
$tab = my_sort($tab);
foreach($tab as $elem)
	echo("$elem\n");
?>
