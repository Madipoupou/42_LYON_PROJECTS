<?php
class Vector {
    // Attributes
    public static $verbose;
    private $_x;
    private $_y;
    private $_z;
    private $_w = 0.0;

    // Constructor
    function __construct( array $kwargs ) {
        if ( array_key_exists( 'dest', $kwargs ) && $kwargs['dest'] instanceof Vertex ) {
            if ( !array_key_exists( 'orig', $kwargs ) ) {
                $kwargs['orig'] = new Vertex( array( 'x' => 0, 'y' => 0, 'z' => 0 ) );
            }
            $this->_x = $kwargs['dest']->getX() - $kwargs['orig']->getX();
            $this->_y = $kwargs['dest']->getY() - $kwargs['orig']->getY();
            $this->_z = $kwargs['dest']->getZ() - $kwargs['orig']->getZ();
        }
        if ( self::$verbose )
            printf( "Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed\n", $this->_x, $this->_y, $this->_z, $this->_w );
    }

    // Desctructor
    function __destruct() {
        if ( self::$verbose )
            printf( "Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) destructed\n", $this->_x, $this->_y, $this->_z, $this->_w );
    }

    // toString
    function __toString() {
        return ( sprintf( "Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )", $this->_x, $this->_y, $this->_z, $this->_w ) );
    }

    // doc function, returns the documentation about the Class
    public static function doc() {
        if ( file_exists( "./Vector.doc.txt" ) )
            return ( file_get_contents( "./Vector.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
    }

    // Returns the magnitude of the vector
    public function magnitude() {
        return ( sqrt( $this->_x * $this->_x + $this->_y * $this->_y + $this->_z * $this->_z ) );
    }

    // Returns a normalized copy of the vector
    public function normalize() {
        if ( $this->magnitude() != 0 ) {
            $dest = array(
                'x' => $this->_x / $this->magnitude(),
                'y' => $this->_y / $this->magnitude(),
                'z' => $this->_z / $this->magnitude()
            );
        }
        else {
            $dest = array(
                'x' => $this->_x,
                'y' => $this->_y,
                'z' => $this->_z
            );
        }
        return ( new Vector( array( 'dest' => new Vertex( $dest ) ) ) );
    }

    // Returns a copy of the addition of this and the vector given as an argument
    public function add( Vector $rhs ) {
        $dest = array(
            'x' => $this->_x + $rhs->getX(),
            'y' => $this->_y + $rhs->getY(),
            'z' => $this->_z + $rhs->getZ()
        );
        return ( new Vector( array( 'dest' => new Vertex( $dest ) ) ) );
    }

    // Returns a copy of the substraction of this and the vector given as an argument
    public function sub( Vector $rhs ) {
        $dest = array(
            'x' => $this->_x - $rhs->getX(),
            'y' => $this->_y - $rhs->getY(),
            'z' => $this->_z - $rhs->getZ()
        );
        return ( new Vector( array( 'dest' => new Vertex( $dest ) ) ) );
    }

    // Returns a Vector which is the opposite
    public function opposite() {
        $dest = array(
            'x' => -1 * $this->_x,
            'y' => -1 * $this->_y,
            'z' => -1 * $this->_z
        );
        return ( new Vector( array( 'dest' => new Vertex( $dest ) ) ) );
    }

    // Returns the scalar product of this and the arg
    public function scalarProduct( $k ) {
        $dest = array(
            'x' => $k * $this->_x,
            'y' => $k * $this->_y,
            'z' => $k * $this->_z
        );
        return ( new Vector( array( 'dest' => new Vertex( $dest ) ) ) );
    }

    // Returns the scalar product of this and the arg vectore
    public function dotProduct( Vector $rhs ) {
        $tot = $this->_x * $rhs->getX() + $this->_y * $rhs->getY() + $this->_z * $rhs->getZ();
        return ( $tot );
    }

    // Returns cos of angle between this and arg vector
    public function cos( Vector $rhs ) {
        $cos = $this->dotProduct( $rhs ) / ( $this->magnitude() * $rhs->magnitude() );
        return ( $cos );
    }

    // Returns the cross product of this and arg vector
    public function crossProduct( Vector $rhs ) {
        $dest = array(
            'x' => $this->_y * $rhs->getZ() - $this->_z * $rhs->getY(),
            'y' => $this->_z * $rhs->getX() - $this->_x * $rhs->getZ(),
            'z' => $this->_x * $rhs->getY() - $this->_y * $rhs->getX()
        );
        return ( new Vector( array( 'dest' => new Vertex( $dest ) ) ) );
    }

    // Getters
	public function getX() { return ( $this->_x ); }
	public function getY() { return ( $this->_y ); }
	public function getZ() { return ( $this->_z ); }
	public function getW() { return ( $this->_w ); }
}
?>