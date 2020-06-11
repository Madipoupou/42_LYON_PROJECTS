<?php
class Camera {
    // Attributes
    public static $verbose = False;
    private $_origin;
    private $_orientation;
    private $_width;
    private $_height;
    private $_ratio;
    private $_fov;
    private $_near;
    private $_far;
    private $_tT;
    private $_tR;
    private $_tRtT;
    private $_proj;

    // Constructor
    function __construct(array $kwargs)
    {
        if ( array_key_exists( 'origin', $kwargs ) && isset( $kwargs['origin'] ) ) {
            $this->_origin = $kwargs['origin'];
            $this->ft_eval_tT();
        }    
        if ( array_key_exists( 'orientation', $kwargs ) && isset( $kwargs['orientation'] ) ) {
            $this->_orientation = $kwargs['orientation'];
            $this->ft_eval_tR();
        }
        if ( array_key_exists( 'width', $kwargs ) && isset( $kwargs['width'] ) && array_key_exists( 'height', $kwargs ) && isset( $kwargs['height'] ) ) {
            $this->_width = $kwargs['width'];
            $this->_height = $kwargs['height'];
            $this->_ratio = $this->_width / $this->_height;
        }
        else if ( array_key_exists( 'ratio', $kwargs ) && isset( $kwargs['ratio'] ) )
            $this->_ratio = $kwargs['ratio'];
        if ( array_key_exists( 'fov', $kwargs ) && isset( $kwargs['fov'] ) )
            $this->_fov = $kwargs['fov'];
        if ( array_key_exists( 'near', $kwargs ) && isset( $kwargs['near'] ) )
            $this->_near = $kwargs['near'];
        if ( array_key_exists( 'far', $kwargs ) && isset( $kwargs['far'] ) )
            $this->_far = $kwargs['far'];
        if ( true ) {
            $this->ft_eval_proj();
        }
        if ( isset( $this->_tT ) && isset( $this->_tR ) )
            $this->ft_eval_tRtT();
        if ( self::$verbose )
            printf( "Camera instance constructed\n" );
    }

    // Desctructor
    function __destruct() {
        if ( self::$verbose )
        printf( "Camera instance destructed\n" );
    }

    // Evaluation of attributes which enable transformations
    private function ft_eval_tT() {
        $tempVector = new Vector( array( 'dest' => $this->_origin ) );
        $this->_tT = new Matrix( array( 'preset' => Matrix::TRANSLATION, 'vtc' => $tempVector->opposite() ) );
    }
    private function ft_eval_tR() {
        $this->_tR = new Matrix( array( 'preset' => Matrix::TRANSPOSE, 'transpose' => $this->_orientation ));
    }
    private function ft_eval_proj() {
        $this->_proj = new Matrix ( array( 'preset' => Matrix::PROJECTION, 'fov' => $this->_fov, 'far' => $this->_far, 'near' => $this->_near, 'ratio' => $this->_ratio ) );
    }
    private function ft_eval_tRtT() {
        $this->_tRtT = $this->_tR->mult( $this->_tT );
    }

    // toString
    function __toString() {
        $str = "Camera(\n";
        $str .= "+ Origine: %s\n";
        $str .= "+ tT:\n%s\n";
        $str .= "+ tR:\n%s\n";
        $str .= "+ tR->mult( tT ):\n%s\n";
        $str .= "+ Proj:\n%s\n)";
        return ( vsprintf($str, array( $this->_origin, $this->_tT, $this->_tR, $this->_tRtT, $this->_proj ) ) );
    }

    // doc function, returns the documentation about the Class
    public static function doc() {
        if ( file_exists( "./Camera.doc.txt" ) )
            return ( file_get_contents( "./Camera.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
    }

    // Converts "world vertex" into "screen vertex" displayable
    public function watchVertex( Vertex $worldVertex ) {
		$temp = $this->_tRtT->transformVertex( $worldVertex );
		$temp = $this->_proj->transformVertex( $temp );
		return ($temp );
    }
}
?>