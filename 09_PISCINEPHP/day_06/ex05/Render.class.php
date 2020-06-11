<?php
header( "Content-type: image/png" );
class Render {
    // CONST
    const VERTEX = 'vertex';
    const EDGE = 'edge';
    const RASTERIZE = 'rasterize';

    // Attributes
    public static $verbose = False;
    private $_width;
    private $_height;
    private $_filename;
    private $_image;
    private $_mode;

    // Constructor
    function __construct( array $kwargs ) {
        if ( array_key_exists( 'width', $kwargs ) && array_key_exists( 'height', $kwargs ) && array_key_exists( 'filename', $kwargs ) ) {
            $this->_width = intval( $kwargs['width'] );
            $this->_height = intval( $kwargs['height'] );
            $this->_filename = $kwargs['filename'];
            $this->_image = imagecreate( $this->_width, $this->_height );
            if ( array_key_exists( 'background', $kwargs ) ) {
                $red = $kwargs['background']->red;
                $green = $kwargs['background']->green;
                $blue = $kwargs['background']->blue;
                imagecolorallocate( $this->_image, $red, $green, $blue );
            }
            else
                imagecolorallocate( $this->_image, 0, 0, 0 );
            if ( array_key_exists( 'mode', $kwargs ) ) {
                $this->_mode = $kwargs['mode'];
            }
            else
            $this->_mode = self::VERTEX;
        }
        if ( self::$verbose )
            printf( "A Render has been constructed.\n" );
    }

    // Destructor
    function __destruct() {
        if ( self::$verbose )
            printf( "A Render has been destroyed.\n" );
    }

    // doc method
    public static function doc() {
        if ( file_exists( "./Render.doc.txt" ) )
            return ( file_get_contents( "./Render.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
    }

    // Displays a render as vertex
    function renderVertex( Vertex $screenVertex ) {
        $color = imagecolorallocate($this->_image, $screenVertex->getColor()->red, $screenVertex->getColor()->green, $screenVertex->getColor()->blue);
        imagesetpixel($this->_image, $screenVertex->getX() + $this->_width / 2, $screenVertex->getY() + $this->_height / 2, $color);
    }

    // Displays a render as edge
    public function renderEdge(Vertex $a, Vertex $b) {
        $color = imagecolorallocate($this->_image, $a->getColor()->red, $a->getColor()->green, $a->getColor()->blue);
        ImageLine ($this->_image, $a->getX() + $this->_width / 2, $a->getY() + $this->_height / 2, $b->getX() + $this->_width / 2, $b->getY() + $this->_height / 2, $color);
    }

    // Displays a triangle
    function renderTriangle( Triangle $triangle, $mode ) {
        if ( $mode === 0 ) {
            $this->renderVertex( $triangle->getA() );
            $this->renderVertex( $triangle->getB() );
            $this->renderVertex( $triangle->getC() );
        }
        elseif ( $mode === 1 ) {
            $this->renderEdge( $triangle->getA(), $triangle->getB() );
            $this->renderEdge( $triangle->getB(), $triangle->getC() );
            $this->renderEdge( $triangle->getC(), $triangle->getA() );
        }
    }

    // Saves the PNG image created using $this->_filename
    function develop() {
        imagestring( $this->_image, 1, $this->_width - 60, $this->_height - 20, "By mhotting", 16777210);
        imagepng( $this->_image, $this->_filename );
    }
}
?>