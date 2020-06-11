<?php

class Grille {
    use Doc;
    // Attributes
    private $_height;
    private $_width;
    private $_colorJ1;
    private $_colorJ2;
    private $_colorObs;
    private $_matrix;

    // Constructor
    public function __construct($width, $height) {
        $this->_width = $width;
        $this->_height = $height;
        $temp = array();
        for ($i = 0; $i < $height; $i++) {
            for ($j = 0; $j < $width; $j++)
                $temp[$i][$j] = 0;
        }
        $this->_matrix = $temp;
        $this_colorJ1 = 1;
        $this_colorJ2 = 2;
        $this_colorObs = 3;
    }

    // toString
    public function __toString() {
        $str = "";
        $str .= "<table>";
        for ($i = 0; $i < $this->_height; $i++) {
            $str .= "<tr>";
            for ($j = 0; $j < $this->_width; $j++) {
                switch ($this->_matrix[$i][$j]) {
                    case 0:
                        $str .= '<td class="vide">';
                        break ;
                    case 1:
                        $str .= '<td class="j1">';
                        break ;
                    case 2:
                        $str .= '<td class="j2">';
                        break ;
                    case 3:
                        $str .= '<td class="obs">';
                        break ;
                }
                $str .= "</td>";
            }
            $str .= "</tr>";
        }
        $str .= "</table>";
        return ($str);
    }

    // Reset the matrix
    public function resetMatrix() {
        $temp = array();
        for ($i = 0; $i < $this->_height; $i++) {
            for ($j = 0; $j < $this->_width; $j++)
                $temp[$i][$j] = 0;
        }
        $this->_matrix = $temp;
    }

    // Getters
    public function getMatrix() { return ($this->_matrix); }

    // Setters
    public function setMatrix($newMatrix) {
        $this->_matrix = $newMatrix;
    }
}

?>