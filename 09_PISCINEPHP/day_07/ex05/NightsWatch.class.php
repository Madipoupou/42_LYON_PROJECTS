<?php

class NightsWatch {
    // Attributes
    private $_fighters = array();

    // Store the arg in the array of fighters only if it is an instance of fighter
    public function recruit( $fighter ) {
        $this->_fighters[] = $fighter;
    }

    // Make all the fighters fight
    public function fight() {
        foreach ( $this->_fighters as $fighter ) {
            if ( $fighter instanceof IFighter )
                $fighter->fight();
        }
    }
}

?>