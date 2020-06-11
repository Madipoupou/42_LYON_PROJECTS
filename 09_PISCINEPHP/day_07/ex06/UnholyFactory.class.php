<?php

class UnholyFactory {
    // Attributes
    private $_knownTypes = array();

    // Absorbs a new type of fighter and stores it in the _knownTypes array
    public function absorb( /*Fighter*/ $fighter ) {
        if ( $fighter instanceof Fighter ) {
            $type = $fighter->getType();
            if ( array_key_exists( $type, $this->_knownTypes ) ) {
                print( "(Factory already absorbed a fighter of type " . $type . ")\n" );
            } else {
                $this->_knownTypes[ $type ] = $fighter;
                print( "(Factory absorbed a fighter of type " . $type . ")\n" );
            }
        }
        else
            print( "(Factory can't absorb this, it's not a fighter)\n" );
    }

    // Creates a new instance of $type fighter if it is possible
    public function fabricate( $type ) {
        if ( array_key_exists( $type, $this->_knownTypes ) ) {
            print( "(Factory fabricates a fighter of type " . $type . ")\n" );
            return ( clone $this->_knownTypes[$type] );
        }
        print( "(Factory hasn't absorbed any fighter of type " . $type . ")\n" );
        return ( null );
    }
}

?>