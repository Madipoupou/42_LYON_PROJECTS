<?php
class Vertex {
    // Attributes
    public static $verbose = false;
    private $_x;
    private $_y;
    private $_z;
    private $_w;
    private $_color;
    
    // Constuctor
    function __construct( array $kwargs ) {
        $this->_x = $kwargs['x'];
        $this->_y = $kwargs['y'];
        $this->_z = $kwargs['z'];
        if ( array_key_exists( 'w', $kwargs ) && !empty( $kwargs['w'] ) )
            $this->_w = $kwargs['w'];
		else
			$this->_w = 1.0;
		if ( array_key_exists( 'color', $kwargs ) && $kwargs['color'] instanceof Color )
			$this->_color = $kwargs['color'];
		else
		$this->_color = new Color( array( 'rgb' => ( ( 255 << 8 | 255 ) << 8 ) | 255 ) );
		if ( self::$verbose )
			printf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color );
	}

	// Destructor
	function __destruct() {
		if ( self::$verbose )
			printf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color );
	}

	// toString
	function __toString() {
		if (self::$verbose)
			return ( sprintf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, %s )", $this->_x, $this->_y, $this->_z, $this->_w, $this->_color ) );
		else
			return ( sprintf( "Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w ) );
	}

	// doc function, returns the documentation about the Class
    public static function doc() {
        if ( file_exists( "./Vertex.doc.txt" ) )
            return ( file_get_contents( "./Vertex.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
	}
	
	// Getters
	public function getX() { return ( $this->_x ); }
	public function getY() { return ( $this->_y ); }
	public function getZ() { return ( $this->_z ); }
	public function getW() { return ( $this->_w ); }
	public function getColor() { return ( $this->_color ); }

	// Setters
	public function setX($x) { $this->_x = $x; }
	public function setY($y) { $this->_y = $y; }
	public function setZ($z) { $this->_z = $z; }
	public function setW($w) { $this->_w = $w; }
	public function setColor(Color $newColor) { $this->_color = $newColor; }
}
?>