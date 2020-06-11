<?php

abstract class Fighter {
    // Attributes
    protected $_type;

    // Constructor
    function __construct( $type ) {
        if ( isset( $type ) )
            $this->_type = $type;
    }

    // Get the fighter type
    public function getType() {
        return ( $this->_type );
    }

    // Function fight must be implemented
    abstract function fight( $target );
}

?>