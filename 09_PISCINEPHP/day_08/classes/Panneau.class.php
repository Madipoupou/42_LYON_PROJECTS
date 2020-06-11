<?php

class Panneau {
    use Doc;
    // Attributes
    private $_coup;
    private $_joueur;

    // Constructor
    public function __construct($joueur) {
        $this->_coup = 5;
        $this->_joueur = $joueur;
    }

    //toString
    public function __toString() {
        $nbJ = $this->_joueur->getPartie()->getCurrent();
        $ennemi = ($nbJ == 1 ? 2 : 1);
        $str = "";
        $str .= "<h3>Joueur: " . $this->_joueur->getName() . "</h3>";
        $str .= "<p>Nombre de coups: " . $this->_coup . "</p>";
        $flotte = $this->_joueur->getFlotte();
        foreach ($flotte as $nb => $vaisseau) {
            $up = "<a href=\"./controller.php?action=move&axe=y&coeff=-1&nbJ=" . $nbJ. "&nbV=" . $nb . "\">Haut</a>";
            $down = "<a href=\"./controller.php?action=move&axe=y&coeff=1&nbJ=" . $nbJ. "&nbV=" . $nb . "\">Bas</a>";
            $left = "<a href=\"./controller.php?action=move&axe=x&coeff=-1&nbJ=" . $nbJ. "&nbV=" . $nb . "\">Gauche</a>";
            $right = "<a href=\"./controller.php?action=move&axe=x&coeff=1&nbJ=" . $nbJ. "&nbV=" . $nb . "\">Droite</a>";
            $shoot = "<a href=\"./controller.php?action=shoot&nbJ=" . $nbJ. "&nbV=" . $nb . "&ennemi=" . $ennemi . "\">Tirer</a>";
            $reload = "<a href=\"./controller.php?action=load&nbJ=" . $nbJ. "&nbV=" . $nb . "\">Recharger bouclier</a>";
            $wait = "<a href=\"./controller.php?action=wait&nbJ=" . $nbJ. "&nbV=" . $nb . "\">Attendre</a>";
            $vie = $vaisseau->getVie();
            $vitesse = $vaisseau->getVitesse();
            $bouclier = $vaisseau->getBouclier();
            $dir = $vaisseau->getDir();
            $dirName = ($dir == 1 ? "haut" : ($dir == 2 ? "Droite" : ($dir == 3 ? "Bas" : "Gauche")));
            $attaque = $vaisseau->getArme()->getDegat();
            $portee = $vaisseau->getArme()->getPortee();
            $str.= "<table>";
            $str .= "<tr><td colspan=\"4\">". $vaisseau->getName() . " numéro " . $nb . "</td></tr>";
            $str .= "<tr><td></td><td>" . $up . "</td><td></td><td>" . $shoot . "</td></tr>";
            $str .= "<tr><td>" . $left . "</td><td></td><td>" . $right . "</td><td>" . $reload . "</td></tr>";
            $str .= "<tr><td></td><td>" . $down . "</td><td></td><td>" . $wait . "</td></tr>";
            $str .= "<tr><td>PV: " . $vie . "</td><td>PB: " . $bouclier . "</td><td>Vit: " . $vitesse . "</td><td>Dir: ". $dirName . "</td></tr>";
            $str .= "<tr><td colspan=\"2\">Attaque: " . $attaque . "</td><td colspan=\"2\">Portee: " . $portee . "</td></tr>";

            $str .= "</table><br />";
        }
        return ($str);
    }

    // Diminue le nb de coups restants
    public function coupFini($nb) {
        $this->_coup -= $nb;
    }

    // Getters
    public function getCoup() { return ($this->_coup); }
}

?>