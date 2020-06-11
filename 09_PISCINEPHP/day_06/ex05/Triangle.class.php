<?php
class Triangle {
    // Attributes
    public static $verbose = False;
    private $_A;
    private $_B;
    private $_C;

    // Constructor
    function __construct( array $kargvs ) {
        if ( array_key_exists( 'A', $kargvs ) && array_key_exists( 'B', $kargvs ) && array_key_exists( 'C', $kargvs ) ) {
            $this->_A = $kargvs['A'];
            $this->_B = $kargvs['B'];
            $this->_C = $kargvs['C'];
        }
        if ( self::$verbose )
            printf( "A triangle has been created.\n" );
    }

    // Destructor
    function __destruct() {
        if ( self::$verbose )
           printf( "A triangle has been destructed.\n" );
    }

    // toString
    function __toString() {
        return( sprintf("Triangle:\n%s\n%s\n%s", $this->_A, $this->_B, $this->_B) );
    }

    // doc method
    public static function doc() {
        if ( file_exists( "./Triangle.doc.txt" ) )
            return ( file_get_contents( "./Triangle.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
    }

    // Getters
    public function getA() { return ( $this->_A ); }
    public function getB() { return ( $this->_B ); }
    public function getC() { return ( $this->_C ); }
}
?>