#!/usr/bin/php
<?PHP

if ($argc === 1 || !file_exists($argv[1]))
	exit();
$str = file_get_contents($argv[1]);
$str = preg_replace_callback(
	"/(<a )(.*?)(>)(.*)(<\/a>)/s",
	function ($matches) {
		$matches[0] = preg_replace_callback(
			"/(title=\")(.*?)(\">)/s",
			function ($matches)
			{
				return ($matches[1].strtoupper($matches[2]).$matches[3]);
			},
			$matches[0]);
		$matches[0] = preg_replace_callback(
			"/(>)(.*?)(<)/s",
			function ($matches)
			{
				return ($matches[1].strtoupper($matches[2]).$matches[3]);
			},
			$matches[0]);
		return ($matches[0]);
	},
	$str);
echo($str);

?>
