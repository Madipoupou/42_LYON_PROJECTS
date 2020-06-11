<fieldset>
    <h1>Inscription</h1>
    <form action="./index.php" method="post">
    <table>
        <?php
            if (isset($_GET['error'])) {
                if ($_GET['error'] == 'empty')
                    echo('<tr><td colspan="2" class="error">*Erreur: tous les champs doivent être remplis.</td></tr>');
                elseif ($_GET['error'] == 'db')
                    echo('<tr><td colspan="2" class="error">*Erreur: problème de serveur, retentez plus tard.</td></tr>');
                elseif ($_GET['error'] == 'letternum')
                    echo('<tr><td colspan="2" class="error">*Erreur: pseudo et mot de passe ne doivent contenir que des lettres et chiffres.</td></tr>');
                elseif ($_GET['error'] == 'pwdmatch')
                    echo('<tr><td colspan="2" class="error">*Erreur: les mots de passe sont différents.</td></tr>');
                elseif ($_GET['error'] == 'pwdcontent')
                    echo('<tr><td colspan="2" class="error">*Erreur: le mot de passe ne doit contenir que des lettres, chiffres et points.<br />Les points sont optionnels, un chiffre est imposé.</td></tr>');
                elseif ($_GET['error'] == 'pseudocontent')
                    echo('<tr><td colspan="2" class="error">*Erreur: le pseudo ne doit contenir que des lettres, chiffres et points.</td></tr>');
                elseif ($_GET['error'] == 'pwdlen')
                    echo('<tr><td colspan="2" class="error">*Erreur: le mot de passe doit contenir entre 6 et 15 caractères.</td></tr>');
                elseif ($_GET['error'] == 'pseudoexists')
                    echo('<tr><td colspan="2" class="error">*Erreur: le pseudo est déjà emprunté par un utilisateur.</td></tr>');
                elseif ($_GET['error'] == 'mailexists')
                    echo('<tr><td colspan="2" class="error">*Erreur: le mail est déjà emprunté par un utilisateur.</td></tr>');
                elseif ($_GET['error'] == 'pseudolen')
                    echo('<tr><td colspan="2" class="error">*Erreur: le pseudo doit contenir entre 3 et 15 caractères.</td></tr>');
                elseif ($_GET['error'] == 'mail_format')
                    echo('<tr><td colspan="2" class="error">*Erreur: l\'adresse mail est incorrecte.</td></tr>');
                else
                    echo('<tr><td colspan="2" class="error">*Erreur: problème de serveur, retentez plus tard.</td></tr>');
            }
            ?>
        <input type="hidden" name="action" value="suscribechecker"
        <tr>
            <td>Votre pseudo:</td>
            <td><input type="text" name="pseudo" placeholder="Saisir pseudo" autofocus required></td>
        </tr>
        <tr>
            <td>Votre adresse mail:</td>
            <td><input type="email" name="mail" placeholder="Saisir adresse email" required></td>
        </tr>
        <tr>
            <td>Votre mot de passe:</td>
            <td><input type="password" name="pwd" placeholder="Saisir mot de passe" required></td>
        </tr>
        <tr>
            <td>Confirmez votre mot de passe:</td>
            <td><input type="password" name="pwd_confirm" placeholder="Confirmer mot de passe" required></td>
        </tr>
        <tr>
            <td colspan="2"><button class="btn btn-primary my-2 my-sm-0" type="submit">Ok</button></td>
        </tr>
    </table>
    </form>
</fieldset>