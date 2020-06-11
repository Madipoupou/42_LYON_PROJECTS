<?PHP

function ft_is_sort($tab)
{
	$cpy = $tab;
	sort($cpy);
	$size = sizeof($tab);
	for ($i = 0; $i < $size; $i++)
	{
		if ($tab[$i] != $cpy[$i])
			return (FALSE);
	}
	return (TRUE);
}

?>
