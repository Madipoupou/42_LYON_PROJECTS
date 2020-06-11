<?php

class Jaime extends Lannister {
    public function sleepWith( $who ) {
        if ( $who instanceof Cersei )
            echo( "With pleasure, but only in a tower in Winterfell, then.\n" );
        elseif ( $who instanceof Lannister )
            echo( "Not even if I'm drunk !\n" );
        elseif ( $who instanceof Sansa )
            echo( "Let's do this.\n" );
    }
}

?>