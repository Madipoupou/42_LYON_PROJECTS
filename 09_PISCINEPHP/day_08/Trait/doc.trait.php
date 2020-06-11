<?php

trait Doc {
    public static function doc() {
        $className = static::class;
        $docname = "./classes/" . $className . ".class.txt";
        if (file_exists($docname))
            $str = file_get_contents($docname);
        else
            $str = "Impossible de récupérer la documentation.";
        return ($str);
    }
}

?>