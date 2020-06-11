<?php

/* Create basket */
function ft_create_basket()
{
    if (!isset($_SESSION["panier"]))
    {
        $_SESSION["panier"] = array();
        $_SESSION["panier"]["nom_organe"] = array();
        $_SESSION["panier"]["donneur"] = array();
        $_SESSION["panier"]["qt_organe"] = array();
        $_SESSION["panier"]["prix_organe"] = array();
        $_SESSION["panier"]["verrou"] = false;
    }
    return (true);
}

/* Add article to basket */
function ft_add_organe($nom_organe, $donneur, $prix_organe)
{
    if (ft_create_basket() && $_SESSION["panier"]["verrou"] === false)
    {
        $pos_organe = array_search($nom_organe, $_SESSION["panier"]["nom_organe"]);
        if ($pos_organe !== false)
            $_SESSION["panier"]["qt_organe"][$pos_organe]++;
        else
        {
            $_SESSION["panier"]["nom_organe"][] = $nom_organe;
            $_SESSION["panier"]["donneur"][] = $donneur;
            $_SESSION["panier"]["qt_organe"][] = 1;
            $_SESSION["panier"]["prix_organe"][] = $prix_organe;
        }
    }
    else
        echo("Erreur - Impossible d'accéder au panier.\n");
}

/* Remove article using temp array */
function ft_rem_organe($nom_organe, $donneur)
{
    if (ft_create_basket() && !$_SESSION["panier"]["verrou"])
    {
        $tmp = array();
        $tmp["nom_organe"] = array();
        $tmp["donneur"] = array();
        $tmp["qt_organe"] = array();
        $tmp["prix_organe"] = array();
        $tmp["verrou"] = $_SESSION["panier"]["verrou"];
        for ($i = 0; $i < sizeof($_SESSION["panier"]["nom_organe"]); $i++)
        {
            if ($_SESSION["panier"]["nom_organe"][$i] !== $nom_organe || $_SESSION["panier"]["donneur"][$i] !== $donneur)
            {
                $tmp["nom_organe"][] = $_SESSION["panier"]["nom_organe"][$i];
                $tmp["donneur"][] = $_SESSION["panier"]["donneur"][$i];
                $tmp["qt_organe"][] = $_SESSION["panier"]["gt_organe"][$i];
                $tmp["prix_organe"][] = $_SESSION["panier"]["prix_organe"][$i];
            }
        }
        $_SESSION["panier"] = $tmp;
        unset($tmp);
    }
    else
        echo("Erreur - Impossible d'accéder au panier.");   
}

/* Edit organe quantity in the basket */
function ft_edit_qt($nom_organe, $donneur, $variation)
{
    if (ft_create_basket() && !$_SESSION["panier"]["verrou"])
    {
        $pos_organe = 0;
        while ($pos_organe < sizeof($_SESSION["panier"]["nom_organe"]))
        {
            if ($_SESSION["panier"]["nom_organe"][$pos_organe] === $nom_organe && $_SESSION["panier"]["donneur"][$pos_organe] === $donneur)
                break ;
            $pos_organe++;
        }
        if ($pos_organe < sizeof($_SESSION["panier"]["nom_organe"]))
        {
            $_SESSION["panier"]["qt_organe"][$pos_organe] += $variation;
            if ($_SESSION["panier"]["qt_organe"][$pos_organe] <= 0)
                ft_rem_organe($nom_organe, $donneur);
        }
    }
    else
        echo("Erreur - Impossible d'accéder au panier."); 
}

/* Amount of the basket */
function ft_basket_amount()
{
    $amount = 0;
    for ($i = 0; $i < sizeof($_SESSION["panier"]["nom_organe"]); $i++)
        $amount += $_SESSION["panier"]["qt_organe"][$i] * $_SESSION["panier"]["prix_organe"][$i];
    return ($amount);
}

/* Count number of articles in the basket */
function ft_count_basket()
{
    if (isset($_SESSION["panier"]))
        return (count($_SESSION["panier"]["nom_organe"]));
    else
        return (0);
}

/* Remove basket */
function ft_rem_basket()
{
    unset($_SESSION["panier"]);
}

?>