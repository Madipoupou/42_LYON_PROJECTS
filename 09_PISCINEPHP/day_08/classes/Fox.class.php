<?php

final class Fox extends Vaisseau {
    use Doc;
    // Constructor
    public function __construct($xinit, $yinit, $dir) {
        parent::__construct($xinit, $yinit, $dir);
        $this->_name = "Fox";
        $this->_vie = 5;
        $this->_bouclier = 3;
        $this->_bouclierMax = 3;
        $this->_width = 1;
        $this->_height = 1;
        $this->_vitesse = 8;
        $this->_arme = new Blaster($this);
    }
}

?>