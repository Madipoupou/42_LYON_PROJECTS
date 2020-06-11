<?php
class Matrix {
    // Constant att
    const IDENTITY = 'IDENTITY';
    const SCALE = 'SCALE';
    const RX = 'Ox ROTATION';
    const RY = 'Oy ROTATION';
    const RZ = 'Oz ROTATION';
    const TRANSLATION = 'TRANSLATION';
    const PROJECTION = 'PROJECTION';
    const PRODUCT = 'PRODUCT';
    const TRANSPOSE = 'TRANSPOSE';

    // Attributes
    public static $verbose = False;
    private $_preset;
    private $_scale;
    private $_angle;
    private $_vtc;
    private $_fov;
    private $_ratio;
    private $_near;
    private $_far;
    private $_matrix;

    // Constructor
    function __construct(array $kwargs)
    {
        $this->ft_init();
        $this->_preset = $kwargs['preset'];
        switch ( $this->_preset ) {
            case ( self::IDENTITY ): {
                break ;
            }
            case ( self::SCALE ): {
                $this->ft_init_scale($kwargs);
                break ;
            }
            case ( self::RX ): {
                $this->ft_init_rx($kwargs);
                break ;
            }
            case ( self::RY ): {
                $this->ft_init_ry($kwargs);
                break ;
            }
            case ( self::RZ ): {
                $this->ft_init_rz($kwargs);
                break ;
            }
            case ( self::TRANSLATION ): {
                $this->ft_init_trans($kwargs);
                break ;
            }
            case ( self::PROJECTION ): {
                $this->ft_init_proj($kwargs);
                break ;
            }
            case ( self::PRODUCT ): {
                $this->ft_init_mul($kwargs);
                break ;
            }
            case ( self::TRANSPOSE ): {
                $this->ft_init_transpose($kwargs);
                break ;
            }
            default:
                echo("Error - Read the class documentation before using it.\n" );
        }
        if ( self::$verbose && $this->_preset != self::PRODUCT )
            printf( "Matrix %s instance constructed\n", $this->_preset );
    }

    // Initialize attributes to default values
    private function ft_init() {
        $this->_matrix = array(
            '0' => array(1, 0, 0, 0),
            '1' => array(0, 1, 0, 0),
            '2' => array(0, 0, 1, 0),
            '3' => array(0, 0, 0, 1)
        );
        $vtemp = new Vertex( array ( 'x' => 0, 'y' => 0, 'z' => 0 ) );
        $this->_vtc = new Vector( array( 'dest' => $vtemp ) );
        $this->_scale = 1;
        $this->_angle = 0;
        $this->_fov = 0;
        $this->_ratio = 0;
        $this->_near = 0;
        $this->_far = 0;
    }

    // Matrix initializers
    private function ft_init_scale($kwargs) {
        if ( array_key_exists( 'scale', $kwargs ) ) {
            $this->_scale = $kwargs['scale'];
            $this->_matrix[0][0] *= $kwargs['scale'];
            $this->_matrix[1][1] *= $kwargs['scale'];
            $this->_matrix[2][2] *= $kwargs['scale'];
        }
    }
    private function ft_init_rx($kwargs) {
        if ( array_key_exists( 'angle', $kwargs ) ) {
            $this->_angle = $kwargs['angle'];
            $this->_matrix[1][1] = cos($this->_angle);
            $this->_matrix[1][2] = -1 * sin($this->_angle);
            $this->_matrix[2][1] = sin($this->_angle);
            $this->_matrix[2][2] = cos($this->_angle);
        }
    }
    private function ft_init_ry($kwargs) {
        if ( array_key_exists( 'angle', $kwargs ) ) {
            $this->_angle = $kwargs['angle'];
            $this->_matrix[0][0] = cos($this->_angle);
            $this->_matrix[0][2] = sin($this->_angle);
            $this->_matrix[2][0] = -sin($this->_angle);
            $this->_matrix[2][2] = cos($this->_angle);
        }
    }
    private function ft_init_rz($kwargs) {
        if ( array_key_exists( 'angle', $kwargs ) ) {
            $this->_angle = $kwargs['angle'];
            $this->_matrix[0][0] = cos($this->_angle);
            $this->_matrix[0][1] = -1 * sin($this->_angle);
            $this->_matrix[1][0] = sin($this->_angle);
            $this->_matrix[1][1] = cos($this->_angle);
        }
    }
    private function ft_init_trans($kwargs) {
        if ( array_key_exists( 'vtc', $kwargs ) ) {
            $this->_matrix[0][3] = $kwargs['vtc']->getX();
            $this->_matrix[1][3] = $kwargs['vtc']->getY();
            $this->_matrix[2][3] = $kwargs['vtc']->getZ();
            $this->_vtc = $kwargs['vtc'];
        }
    }
    private function ft_init_proj($kwargs) {
        if ( array_key_exists( 'fov', $kwargs ) && array_key_exists( 'far', $kwargs ) && array_key_exists( 'ratio', $kwargs ) && array_key_exists( 'near', $kwargs )) {
            $this->_matrix[1][1] = 1 / tan( 0.5 * deg2rad( $kwargs['fov'] ) );
            $this->_matrix[0][0] = $this->_matrix[1][1] / $kwargs['ratio'];
            $this->_matrix[2][2] = -1 * ( -1 * $kwargs['near'] - $kwargs['far'] ) / ( $kwargs['near'] - $kwargs['far'] );
            $this->_matrix[3][2] = -1;
            $this->_matrix[2][3] = ( 2 * $kwargs['near'] * $kwargs['far'] ) / ( $kwargs['near'] - $kwargs['far'] );
            $this->_matrix[3][3] = 0;
            $this->_near = $kwargs['near'];
            $this->_ratio = $kwargs['ratio'];
            $this->_far = $kwargs['far'];
            $this->_fov = $kwargs['fov'];
        }
    }
    private function ft_init_mul( $kwargs ) {
        if ( array_key_exists( 'prod', $kwargs ) ) {
            for ( $i = 0; $i < 4; $i++ ) {
                for ( $j = 0; $j < 4; $j++)
                    $this->_matrix[$i][$j] = $kwargs['prod'][$i][$j];
            }
        }
    }
    private function ft_init_transpose( $kwargs ) {
        if ( array_key_exists( 'transpose', $kwargs ) ) {
            for ( $i = 0; $i < 4; $i++ ) {
                for ( $j = 0; $j < 4; $j++) {
                    if ( $i === $j )
                        $this->_matrix[$i][$j] = $kwargs['transpose']->getIndex( $i, $j );
                    else
                        $this->_matrix[$i][$j] = $kwargs['transpose']->getIndex( $j, $i );
                }
            }
        }
    }

    // Desctructor
    function __destruct() {
        if ( self::$verbose )
            printf( "Matrix instance destructed\n" );
    }

    // toString
    function __toString() {
        $str = "";
        $str .= "M | vtcX | vtcY | vtcZ | vtxO\n";
        $str .= "-----------------------------\n";
        $str .= "x | %.2f | %.2f | %.2f | %.2f\n";
        $str .= "y | %.2f | %.2f | %.2f | %.2f\n";
        $str .= "z | %.2f | %.2f | %.2f | %.2f\n";
        $str .= "w | %.2f | %.2f | %.2f | %.2f";
        return ( vsprintf( $str, array( $this->_matrix[0][0], $this->_matrix[0][1], $this->_matrix[0][2], $this->_matrix[0][3],
            $this->_matrix[1][0], $this->_matrix[1][1], $this->_matrix[1][2], $this->_matrix[1][3], 
            $this->_matrix[2][0], $this->_matrix[2][1], $this->_matrix[2][2], $this->_matrix[2][3], 
            $this->_matrix[3][0], $this->_matrix[3][1], $this->_matrix[3][2], $this->_matrix[3][3] ) ) );
    }

    // doc function, returns the documentation about the Class
    public static function doc() {
        if ( file_exists( "./Matrix.doc.txt" ) )
            return ( file_get_contents( "./Matrix.doc.txt" ) . "\n" );
        else
            return ( "Impossible to find the documentation.\n" );
    }

    // Getter
    public function getIndex($i, $j) {
        if ( $i >= 0 && $i < 4 && $j >= 0 && $j < 4 )
            return ( $this->_matrix[$i][$j] );
    }

    // Returns the matrix corresponding to this * arg matrix
    public function mult( Matrix $rhs ) {
        $res = array();
        for ( $i = 0; $i < 4; $i++ ) {
            for ( $j = 0; $j < 4; $j++ ) {
                $res[$i][$j] = 0;
                for ( $k = 0; $k < 4; $k++ ) {
                    $res[$i][$j] += $this->_matrix[$i][$k] * $rhs->getIndex($k, $j);
                }
            }
        }
        return ( new Matrix( array( 'preset' => self::PRODUCT, 'prod' => $res ) ) );
    }

    // Returns a Vertex corresponding to this matrix applied to arg vertex
    public function transformVertex( Vertex $vtx ) {
        $res = array();
        for ( $i = 0; $i < 4; $i++ ) {
            $res[$i] = 0;
            for ( $j = 0; $j < 4; $j++ )
                $res[$i] += $this->_matrix[$i][$j] * $vtx->getIndex($j);
        }
        return ( new Vertex( array( 'x' => $res[0], 'y' => $res[1], 'z' => $res[2] ) ) );
    }
}
?>