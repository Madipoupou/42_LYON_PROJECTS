#!/usr/bin/php
<?PHP

/* Returns true if the arg is a date, else returns false */
function ft_is_date($str)
{
	$pattern = '/[0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3} --> [0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3}/';
	if (preg_match($pattern, $str))
		return (true);
	return (false);
}

/* Sorts the tab according to specific exercice comparison */
function ft_sort($array)
{
	$size = sizeof($array);
	for ($i = 0; $i < $size - 1; $i++)
	{
		while ($i < $size - 1 && !ft_is_date($array[$i]))
			$i++;
		if ($i >= $size)
			break ;
		for ($j = $i + 1; $j < $size - 1; $j++)
		{
			while ($j < $size - 1 && !ft_is_date($array[$j]))
				$j++;
			if ($j >= $size)
				break ;
			if ($array[$i] > $array[$j])
			{
				$temp1 = $array[$i];
				$temp2 = $array[$i + 1];
				$array[$i] = $array[$j];
				$array[$i + 1] = $array[$j + 1];
				$array[$j] = $temp1;
				$array[$j + 1] = $temp2;
			}
		}
	}
	return ($array);
}

/********************
**      MAIN       **
********************/
if ($argc < 2 || !file_exists($argv[1]))
	exit();
$fd = fopen($argv[1], "r");
if (!$fd)
	exit();
$str_file = array();
while ($temp = fgets($fd))
	$str_file[] = $temp;
fclose($fd);
$str_file = ft_sort($str_file);
foreach($str_file as $elem)
	echo("$elem");

?>
