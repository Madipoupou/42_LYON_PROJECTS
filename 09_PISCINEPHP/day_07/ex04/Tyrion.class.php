<?php

class Tyrion extends Lannister {
    public function sleepWith( $who ) {
        if ( $who instanceof Lannister )
            echo( "Not even if I'm drunk !\n" );
        elseif ( $who instanceof Sansa )
            echo( "Let's do this.\n" );
    }
}

?>