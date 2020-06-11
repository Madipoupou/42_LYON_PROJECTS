<?php
class Color {
    // Attributes
    public static $verbose = false;
    public $red;
    public $green;
    public $blue;
    
    // Constructor
    function __construct( array $kwargs ) {
        if ( array_key_exists( "rgb", $kwargs ) ) {
            $rgb = intval( $kwargs["rgb"] );
            $this->red = $rgb >> 16 & 255;
            $this->green = $rgb >> 8 & 255;
            $this->blue = $rgb >> 0 & 255;
        }
        elseif ( array_key_exists( "red", $kwargs ) && array_key_exists( "green", $kwargs ) && array_key_exists( "blue", $kwargs ) ) {
            $this->red = intval( $kwargs["red"] );
            $this->green = intval( $kwargs["green"] );
            $this->blue = intval( $kwargs["blue"] );
        }
        if ( self::$verbose )
            printf( "Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue );
    }

    // Destructor
    function __destruct() {
        if ( self::$verbose )
            printf( "Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue );
    }

    // toString
    function __toString() {
        return ( sprintf( "Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue ) );
    }

    // doc function, returns the documentation about the Class
    public static function doc() {
        if ( file_exists( "./Color.doc.txt" ) )
            return ( file_get_contents( "./Color.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
    }

    // Adds each color constitutive and returns a new Color instance
    public function add( Color $colorToAdd ) {
        $colArray = array(
            "red" => $this->red + $colorToAdd->red, 
            "green" => $this->green + $colorToAdd->green, 
            "blue" => $this->blue + $colorToAdd->blue
        );
        return ( new Color( $colArray ) );
    }

    // Substracts each color constitutive and returns a new Color instance
    public function sub( Color $colorToSub ) {
        $colArray = array(
            "red" => $this->red - $colorToSub->red, 
            "green" => $this->green - $colorToSub->green, 
            "blue" => $this->blue - $colorToSub->blue
        );
        return ( new Color( $colArray ) );
    }

    // Multiplies each color constitutive by factor $f and returns a new Color
    public function mult( $f ) {
        $colArray = array(
            "red" => $this->red * $f , 
            "green" => $this->green * $f , 
            "blue" => $this->blue * $f 
        );
        return ( new Color( $colArray ) );
    }

    // Returns the int value of the color
    public function int_col() {
        return ( $this->red * 65536 + $this->green * 256 + $this->blue );
    }
}
?>