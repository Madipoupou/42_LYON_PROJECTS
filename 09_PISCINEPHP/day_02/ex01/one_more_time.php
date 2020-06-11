#!/usr/bin/php
<?PHP

date_default_timezone_set("Europe/Paris");
/* Function that checks if the str containing the date is correct or not */
function check_date($str)
{
	$pattern = "/^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche) [0-9]?[0-9] ([Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]out|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre) [1-9][0-9]{3} [0-9]{2}:[0-9]{2}:[0-9]{2}$/";
	$res = preg_match($pattern, $str);
	if ($res != 1)
		return (false);
	return (true);
}

/********************
**      MAIN       **
********************/
if ($argc < 2)
	exit();
if (check_date($argv[1]) === false)
{
	echo("Wrong Format\n");
	exit();
}
$tab = array_filter(explode(" ", $argv[1]), "strlen");
$tab[2] = strtolower($tab[2]);
$hour = explode(":", $tab[4]);
$month = array(
	"janvier" => 1,
	"février" => 2,
	"fevrier" => 2,
	"mars" => 3,
	"avril" => 4,
	"mai" => 5,
	"juin" => 6,
	"juillet" => 7,
	"aout" => 8,
	"août" => 8,
	"septembre" => 9,
	"octobre" => 10,
	"novembre" => 11,
	"decembre" => 12,
	"décembre" => 12
);
$time = mktime(intval($hour[0]), intval($hour[1]), intval($hour[2]), $month[$tab[2]], intval($tab[1]), intval($tab[3]));
echo("$time\n");

?>
