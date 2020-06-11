<?PHP

function ft_split($str)
{
	$tab = array_filter(explode(' ', $str), "strlen");
	sort($tab);
	return ($tab);
}

?>
