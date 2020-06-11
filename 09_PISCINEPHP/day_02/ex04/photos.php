#!/usr/bin/php
<?PHP

/* Function which "curl" the url given as arg and returns the page content */
function ft_get_page($url)
{
	$session = curl_init($url);
	curl_setopt($session, CURLOPT_HEADER, 1);
	curl_setopt($session, CURLOPT_FOLLOWLOCATION, 1);
	curl_setopt($session, CURLOPT_RETURNTRANSFER, 1);
	$page = curl_exec($session);
	curl_close($session);
	return ($page);
}

/* Function that reads the string from arg and returns the url address of img html tags */
function ft_get_images($page)
{
	$pattern = '/<img[^>]+src=\"(.+?)\"/is';
	preg_match_all($pattern, $page, $matches);
	return ($matches[1]);
}

/* Function that convert into real url the image names returned by ft_get_images */
function ft_images_url($images, $url)
{
	$array = array();
	foreach ($images as $elem)
	{
		if (!preg_match('/http(s)?/s', $elem))
		{
			if (!preg_match('/^\/\//s', $elem))
			{
				$temp = trim($url);
				$temp .= trim($elem);
				$array[] = $temp;
			}
			else
				$array[] = "http:".$elem;
		}
		else
			$array[] = $elem;
	}
	return ($array);
}

/* Function that extracts the name of the image according to its URL */
function ft_get_images_name($images)
{
	foreach ($images as $elem)
	{
		$temp = explode("/", $elem);
		$array[] = $temp[sizeof($temp) - 1];
	}
	return ($array);
}

/* Function that extracts an image from a website and saves it on the computer in the given folder */
function ft_create_file($folder, $image_url, $file_name)
{
	$session = curl_init();
	curl_setopt($session, CURLOPT_HEADER, 0);
	curl_setopt($session, CURLOPT_FOLLOWLOCATION, 1);
	curl_setopt($session, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($session, CURLOPT_BINARYTRANSFER, 1);
	curl_setopt($session, CURLOPT_URL, $image_url);
	$result = curl_exec($session);
	curl_close($session);
	$file = "$folder"."/"."$file_name";
	file_put_contents($file, $result);
}

/* Function that catches the url of website which page is given as arg */
function ft_get_final_url($page)
{
	$temp = explode("\n", $page);
	foreach ($temp as $elem)
	{
		if (preg_match('/^Location/s', $elem))
		{
			$final_url = $elem;
			break ;
		}
	}
	$final_url = preg_replace("/Location: /s", "", $final_url);
	return ($final_url);
}


/********************
**      MAIN       **
********************/
if ($argc < 2)
	exit();
$page = ft_get_page($argv[1]);
if (!$page)
	exit();
$final_url = ft_get_final_url($page);
$images = ft_get_images($page);
if (!$images)
	exit();
if ($final_url)
	$images = ft_images_url($images, $final_url);
else
	$images = ft_images_url($images, $argv[1]);
$names = ft_get_images_name($images);
$url = preg_replace("/http(s)?:\/\//", "", $argv[1]);
mkdir("./$url");
$i = 0;
foreach ($images as $elem)
{
	ft_create_file($url, $elem, $names[$i]);
	$i++;
}

?>
