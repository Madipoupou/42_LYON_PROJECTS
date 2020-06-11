<?php

class Targaryen {
    // Returns true if object resists to fire
    public function resistsFire() {
		return False;
    }
    
    // Burns the object
    public function getBurned() {
        if ( !$this->resistsFire() )
            return ( "burns alive" );
        else
            return ( "emerges naked but unharmed" );
    }
}

?>