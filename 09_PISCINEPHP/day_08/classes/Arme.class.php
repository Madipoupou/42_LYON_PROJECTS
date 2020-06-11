<?php

abstract class Arme {
    use Doc;
    // Attributes
    protected $_degat;
    protected $_portee;
    protected $_vaisseau;

    // Constructor
    public function __construct($vaisseau) {
        $this->_vaisseau = $vaisseau;
    }
 
    // Getters
    public function getDegat() { return ($this->_degat); }
    public function getPortee() { return ($this->_portee); }
}

?>