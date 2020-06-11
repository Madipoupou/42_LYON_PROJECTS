#!/usr/bin/php
<?PHP

/* Function that evaluates the average mark of the group */
function ft_moyenne($note)
{
	$sum = 0;
	$cpt = 0;
	foreach ($note as $line)
	{
		$temp = explode(";", $line);
		if ($temp[2] == "moulinette")
			continue ;
		$sum += $temp[1];
		$cpt++;
	}
	echo($sum / $cpt . "\n");
}

/* Function that evaluates each user's average mark */
function ft_moyenne_user($note)
{
	$current = "";
	$res = array();
	foreach ($note as $elem)
	{
		$temp = explode(";", $elem);
		if ($temp[2] == "moulinette")
			continue ;
		if ($current != $temp[0])
		{
			if ($current != "")
				$res[] = "$current:" . $sum / $cpt . "\n";
			$current = $temp[0];
			$sum = 0;
			$cpt = 0;
		}
		$sum += $temp[1];
		$cpt += 1;
	}
	$res[] = "$current:" . $sum / $cpt . "\n";
	foreach ($res as $elem)
		echo($elem);
}

/* Function that evaluates the average of the gap between moulinette and user marks */
function ft_ecart($note)
{
	$res = array();
	$mouli = array();
	foreach ($note as $elem)
	{
		$temp = explode(";", $elem);
		if ($temp[2] == "moulinette")
			$mouli[$temp[0]] = $temp[1];
	}
	$current = "";
	foreach ($note as $elem)
	{
		$temp = explode(";", $elem);
		if ($temp[2] == "moulinette")
			continue ;
		if ($current != $temp[0])
		{
			if ($current != "")
				$res[] = "$current:" . $sum / $cpt . "\n";
			$current = $temp[0];
			$sum = 0;
			$cpt = 0;
		}
		$sum += ($temp[1] - $mouli[$current]);
		$cpt++;
	}
	$res[] = "$current:" . $sum / $cpt . "\n";
	foreach ($res as $elem)
		echo($elem);

}

$fd = fopen("php://stdin", "r");
if ($fd)
{
	$str = "";
	while ($temp = fgets($fd))
		$str .= $temp;
	$tab = array_filter(explode("\n", $str), "strlen");
	sort($tab);
	$note = array();
	foreach ($tab as $elem)
	{
		$temp = array_filter(explode(";", $elem), "strlen");
		if (sizeof($temp) == 4 && $temp[0] != "User")
			$note[] = $elem;
	}
	if ($argv[1] == "moyenne")
		ft_moyenne($note);
	elseif ($argv[1] == "moyenne_user")
		ft_moyenne_user($note);
	elseif ($argv[1] == "ecart_moulinette")
		ft_ecart($note);
}

?>
