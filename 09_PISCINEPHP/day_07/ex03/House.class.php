<?php

abstract class House {
    // Prints the house whose the object belogs to
    public function introduce() {
        print( "House " . $this->getHouseName() . " of " . $this->getHouseSeat() . " : \"" . $this->getHouseMotto() . "\"\n" );
    }

    // Getters that must be implemented by the childs
    abstract function getHouseName();
    abstract function getHouseSeat();
    abstract function getHouseMotto();
}

?>