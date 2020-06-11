<?php
/* ************************************************************************** */
/*                                                                            */
/*                 main.php for J06                                           */
/*                 Created on : Fri Mar  7 16:15:49 2014                      */
/*                 Made by : David "Thor" GIRON <thor@42.fr>                  */
/*                                                                            */
/* ************************************************************************** */

require_once 'Vertex.class.php';
require_once 'Triangle.class.php';
require_once 'Vector.class.php';
require_once 'Matrix.class.php';
require_once 'Camera.class.php';
require_once 'Render.class.php';


function makeRepere() {
	$red   = new Color( array( 'red' => 255, 'green' => 255   , 'blue' => 255    ) );
	$green = new Color( array( 'red' => 255   , 'green' => 255, 'blue' => 255    ) );
	$blue  = new Color( array( 'red' => 255   , 'green' => 255   , 'blue' => 255 ) );
	$Ox = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0, 'color' => $green ) );
	$X  = new Vertex( array( 'x' => 1.0, 'y' => 0.0, 'z' => 0.0, 'color' => $green ) );
	$Oy = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0, 'color' => $red   ) );
	$Y  = new Vertex( array( 'x' => 0.0, 'y' => 1.0, 'z' => 0.0, 'color' => $red   ) );
	$Oz = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0, 'color' => $blue  ) );
	$Z  = new Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 1.0, 'color' => $blue  ) );
	return array(
		new Triangle( array( "A" => $Ox, "B" => $Ox, "C" => $X ) ),
		new Triangle( array( "A" => $Oy, "B" => $Oy, "C" => $Y ) ),
		new Triangle( array( "A" => $Oz, "B" => $Oz, "C" => $Z ) )
		);
}

function makeColoredCube( $x, $y, $z, $l ) {
	$red     = new Color( array( 'red' => 255, 'green' => 255   , 'blue' => 255    ) );
	$green   = new Color( array( 'red' => 255   , 'green' => 255, 'blue' => 255    ) );
	$blue    = new Color( array( 'red' => 255   , 'green' => 255   , 'blue' => 255 ) );
	$yellow  = new Color( array( 'red' => 255, 'green' => 255, 'blue' => 255    ) );
	$cyan    = new Color( array( 'red' => 255   , 'green' => 255, 'blue' => 255 ) );
	$magenta = new Color( array( 'red' => 255, 'green' => 255  , 'blue' => 255 ) );
	$white   = new Color( array( 'red' => 255, 'green' => 255, 'blue' => 255 ) );
	$grey    = new Color( array( 'red' => 255  , 'green' => 255  , 'blue' => 255   ) );
	$hl = $l / 2.0;
	$a = new Vertex( array( 'x' => $x-$hl, 'y' => $y+$hl, 'z' => $z+$hl, 'color' => $red ) );
	$b = new Vertex( array( 'x' => $x+$hl, 'y' => $y+$hl, 'z' => $z+$hl, 'color' => $green ) );
	$c = new Vertex( array( 'x' => $x+$hl, 'y' => $y+$hl, 'z' => $z-$hl, 'color' => $blue ) );
	$d = new Vertex( array( 'x' => $x-$hl, 'y' => $y+$hl, 'z' => $z-$hl, 'color' => $yellow ) );
	$e = new Vertex( array( 'x' => $x-$hl, 'y' => $y-$hl, 'z' => $z+$hl, 'color' => $magenta ) );
	$f = new Vertex( array( 'x' => $x+$hl, 'y' => $y-$hl, 'z' => $z+$hl, 'color' => $cyan ) );
	$g = new Vertex( array( 'x' => $x+$hl, 'y' => $y-$hl, 'z' => $z-$hl, 'color' => $grey ) );
	$h = new Vertex( array( 'x' => $x-$hl, 'y' => $y-$hl, 'z' => $z-$hl, 'color' => $white ) );
	return array( new Triangle( array( "A" => $a, "B" => $c, "C" => $b ) ), new Triangle( array( "A" => $a, "B" => $d, "C" => $c ) ),
				  new Triangle( array( "A" => $e, "B" => $g, "C" => $h ) ), new Triangle( array( "A" => $e, "B" => $f, "C" => $g ) ),
				  new Triangle( array( "A" => $e, "B" => $b, "C" => $f ) ), new Triangle( array( "A" => $a, "B" => $b, "C" => $e ) ),
				  new Triangle( array( "A" => $d, "B" => $g, "C" => $c ) ), new Triangle( array( "A" => $d, "B" => $h, "C" => $g ) ),
				  new Triangle( array( "A" => $a, "B" => $e, "C" => $h ) ), new Triangle( array( "A" => $a, "B" => $h, "C" => $d ) ),
				  new Triangle( array( "A" => $f, "B" => $c, "C" => $g ) ), new Triangle( array( "A" => $f, "B" => $b, "C" => $c ) )
		);
}

$v  = new Vector( array( 'dest' => new Vertex( array( 'x' => 20.0, 'y' => 20.0, 'z' => 0.0 ) ) ) );
$T  = new Matrix( array( 'preset' => Matrix::TRANSLATION, 'vtc' => $v ) );
$S  = new Matrix( array( 'preset' => Matrix::SCALE, 'scale' => 10.0 ) );
$RY = new Matrix( array( 'preset' => Matrix::RY, 'angle' => M_PI_4 ) );
$RX = new Matrix( array( 'preset' => Matrix::RX, 'angle' => M_PI_4 ) );

$cam = new Camera( array( 'origin' => new Vertex( array( 'x' => 15.0, 'y' => 15.0, 'z' => 80.0 ) ),
						  'orientation' => new Matrix( array( 'preset' => Matrix::RY, 'angle' => M_PI ) ),
						  'width' => 640,
						  'height' => 480,
						  'fov' => 60,
						  'near' => 1.0,
						  'far' => 100.0) );

$renderer = new Render( array( "width" => 640, "height" => 480, "filename" => 'pic.png' ) );

$origin = New Vertex( array( 'x' => 0.0, 'y' => 0.0, 'z' => 0.0 ) );
$origin = $cam->watchVertex( $origin );


$repere = makeRepere();

$temp = array();
foreach ($repere as $tri) {
	$a = $S->transformVertex($tri->getA());
	$b = $S->transformVertex($tri->getB());
	$c = $S->transformVertex($tri->getC());
	$temp[] = new Triangle( array( "A" => $a, "B" => $b, "C" => $c ) );
}
$repere = $temp;

$temp = array();
foreach ($repere as $tri) {
	$a = $cam->watchVertex($tri->getA());
	$b = $cam->watchVertex($tri->getB());
	$c = $cam->watchVertex($tri->getC());
	$temp[] = new Triangle( array( "A" => $a, "B" => $b, "C" => $c ) );
}
$repere = $temp;

foreach ($repere as $tri) {
	$renderer->renderTriangle( $tri, 0 );
}
$renderer->renderVertex( $origin );


$cube = makeColoredCube( 0.0, 0.0, 0.0, 1.0 );
$M = $T->mult( $RX )->mult( $RY )->mult( $S );

$temp = array();
foreach ($cube as $tri) {
	$a = $M->transformVertex($tri->getA());
	$b = $M->transformVertex($tri->getB());
	$c = $M->transformVertex($tri->getC());
	$temp[] = new Triangle( array( "A" => $a, "B" => $b, "C" => $c ) );
}
$cube = $temp;

$temp = array();
foreach ($cube as $tri) {
	$a = $cam->watchVertex($tri->getA());
	$b = $cam->watchVertex($tri->getB());
	$c = $cam->watchVertex($tri->getC());
	$temp[] = new Triangle( array( "A" => $a, "B" => $b, "C" => $c ) );
}
$cube = $temp;

foreach ($cube as $tri) {
	$renderer->renderTriangle($tri, 0);
}

$renderer->develop();

?>
