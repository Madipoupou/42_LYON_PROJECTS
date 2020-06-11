<?php

abstract class Vaisseau {
    use Doc;
    // Attributes
    protected $_name;
    protected $_arme;
    protected $_bouclier;
    protected $_bouclierMax;
    protected $_vie;
    protected $_xpos;
    protected $_ypos;
    protected $_width;
    protected $_height;
    protected $_vitesse;
    protected $_dir;

    // Constructor
    public function __construct($xinit, $yinit, $dir) {
        $this->_xpos = $xinit;
        $this->_ypos = $yinit;
        $this->_dir = $dir;
    }
    
    // Use the weapon
    //abstract public function attaquer();

    // Move x/y axis
    public function move($axe, $coeff) {
        if ($axe == "x")
            $this->moveX($coeff);
        elseif ($axe == "y")
        $this->moveY($coeff);
    }
    private function moveX($signe) {
        $this->_xpos += $signe * $this->_vitesse;
        if ($signe > 0)
            $this->_dir = 2;
        else
        $this->_dir = 4;
    }
    private function moveY($signe) {
        $this->_ypos += $signe * $this->_vitesse;
        if ($signe > 0)
            $this->_dir = 3;
        else
        $this->_dir = 1;
    }

    // Tirer sur un joueur
    public function tirer($ennemi) {
        $flotteEnnemi = $ennemi->getFlotte();
        $x = $this->_xpos;
        $y = $this->_ypos;
        $dir = $this->_dir;
        $arme = $this->_arme;
        foreach ($flotteEnnemi as $vaisseauEnnemi) {
            if ($vaisseauEnnemi == null)
                continue ;
            if ($dir == 1 || $dir == 3) {
                if ($vaisseauEnnemi->getXpos() == $x) {
                    if ($dir == 1 && ($vaisseauEnnemi->getYpos() < $y && $vaisseauEnnemi->getYpos() >= $y - $arme->getPortee()) )
                        $vaisseauEnnemi->subir($arme->getDegat());
                    elseif ($dir == 3 && ($vaisseauEnnemi->getYpos() > $y && $vaisseauEnnemi->getYpos() <= $y + $arme->getPortee()) )
                        $vaisseauEnnemi->subir($arme->getDegat());
                }
            } else {
                if ($vaisseauEnnemi->getYpos() == $y) {
                    if ($dir == 2 && ($vaisseauEnnemi->getXpos() > $x && $vaisseauEnnemi->getXpos() <= $x + $arme->getPortee()) )
                        $vaisseauEnnemi->subir($arme->getDegat());
                    elseif ($dir == 4 && ($vaisseauEnnemi->getXpos() < $x && $vaisseauEnnemi->getXpos() >= $x - $arme->getPortee()) )
                        $vaisseauEnnemi->subir($arme->getDegat());
                }
            }
        }
    }

    // Subir des degats
    private function subir($degat) {
        if ($this->_bouclier > 0)
            $this->_bouclier--;
        else
            $this->_vie--;
    }

    // Recharger bouclier
    public function load() {
        if ($this->_bouclier < $this->_bouclierMax)
            $this->_bouclier++;
    }
    // Getters
    public function getName() { return ($this->_name); }
    public function getXpos() { return ($this->_xpos); }
    public function getYpos() { return ($this->_ypos); }
    public function getHeight() { return ($this->_height); }
    public function getWidth() { return ($this->_width); }
    public function getVie() { return ($this->_vie); }
    public function getVitesse() { return ($this->_vitesse); }
    public function getBouclier() { return ($this->_bouclier); }
    public function getDir() { return ($this->_dir); }
    public function getArme() { return ($this->_arme); }
}

?>