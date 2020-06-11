<?php

$file = "../img/42.png";
$type = "image/png";
header("Content-Type:".$type);
readfile($file);

?>
