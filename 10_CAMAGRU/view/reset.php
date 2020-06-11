<fieldset>
    <h1>Réinitialiser le mot de passe</h1>
    <form action="./index.php" method="post">
    <table>
        <?php
            if (isset($_GET['error'])) {
                if ($_GET['error'] == 'empty')
                    echo('<tr><td colspan="2" class="error">*Erreur: Les deux champs doivent être remplis.</td></tr>');
                elseif ($_GET['error'] == 'match')
                    echo('<tr><td colspan="2" class="error">*Erreur: les mots de passe sont différents.</td></tr>');
                elseif ($_GET['error'] == 'len')
                    echo('<tr><td colspan="2" class="error">*Erreur: le mot de passe doit contenir entre 6 et 15 caractères.</td></tr>');
                elseif ($_GET['error'] == 'content')
                    echo('<tr><td colspan="2" class="error">*Erreur: le mot de passe ne doit contenir que des lettres, chiffres et points.<br />Les points sont optionnels, un chiffre est imposé.</td></tr>');
                else
                    echo('<tr><td colspan="2" class="error">*Erreur: problème de serveur, retentez plus tard.</td></tr>');
            }
        ?>
        <input type="hidden" name="action" value="resetchecker">
        <input type="hidden" name="username" value="<?= $_GET['username'] ?>">
        <input type="hidden" name="key" value="<?= $_GET['key'] ?>">
        <tr>
            <td>Nouveau mot de passe:</td>
            <td><input type="password" name="pwd" placeholder="Saisir mot de passe" autofocus></td>
        </tr>
        <tr>
            <td>Confirmation:</td>
            <td><input type="password" name="pwd_confirm" placeholder="Confirmer mot de passe"></td>
        </tr>
        <tr>
            <td colspan="2"><button class="btn btn-primary my-2 my-sm-0" type="submit">Ok</button></td>
        </tr>
    </table>
    </form>
</fieldset>