<?php

final class Blaster extends Arme {
    use Doc;
    // Constructor
    public function __construct($vaisseau) {
        parent::__construct($vaisseau);
        $this->_degat = 1;
        $this->_portee = 50;
    }
}

?>