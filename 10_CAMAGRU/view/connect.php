<fieldset>
    <h1>Connexion</h1>
    <form action="./index.php" method="post">
    <table>
        <?php
            if (isset($_GET['account']) && $_GET['account'] == 'ok') {
                echo('<tr><td colspan="2" class="account_created">*Compte créé, un mail d\'activation vous a été envoyé.</td></tr>');
            } elseif (isset($_GET['account']) && $_GET['account'] == 'activate') {
                echo('<tr><td colspan="2" class="account_created">*Compte activé, vous pouvez vous connecter!</td></tr>');
            } elseif (isset($_GET['account']) && $_GET['account'] == 'reset') {
                echo('<tr><td colspan="2" class="account_created">*Mot de passe renouvellé, vous pouvez vous connecter!</td></tr>');
            } elseif (isset($_GET['error'])) {
                if ($_GET['error'] == 'empty')
                    echo('<tr><td colspan="2" class="error">*Erreur: tous les champs doivent être remplis.</td></tr>');
                elseif ($_GET['error'] == 'exists')
                    echo('<tr><td colspan="2" class="error">*Erreur: le compte n\'existe pas.</td></tr>');
                elseif ($_GET['error'] == 'reset')
                    echo('<tr><td colspan="2" class="error">*Erreur: impossible de renouveller, contactez le gestionnaire du site.</td></tr>');
                elseif ($_GET['error'] == 'active')
                    echo('<tr><td colspan="2" class="error">*Erreur: le compte n\'est pas actif.</td></tr>');
                elseif ($_GET['error'] == 'activate')
                    echo('<tr><td colspan="2" class="error">*Erreur: activation impossible, contactez le gestionnaire du site.</td></tr>');
                elseif ($_GET['error'] == 'alreadyactivated')
                    echo('<tr><td colspan="2" class="error">*Erreur: le compte est déjà activé.</td></tr>');
                elseif ($_GET['error'] == 'pleaselogin')
                    echo('<tr><td colspan="2" class="error">*Erreur: Veuillez vous identifier.</td></tr>');
                elseif ($_GET['error'] == 'pwd')
                    echo('<tr><td colspan="2" class="error">*Erreur: le mot de passe est erroné.</td></tr>');
                else
                    echo('<tr><td colspan="2" class="error">*Erreur: problème de serveur, retentez plus tard.</td></tr>');
            }
        ?>
        <input type="hidden" name="action" value="connectchecker">
        <tr>
            <td>Votre pseudo:</td>
            <td><input type="text" name="pseudo" placeholder="Saisir pseudo" autofocus required></td>
        </tr>
        <tr>
            <td>Votre mot de passe:</td>
            <td><input type="password" name="pwd" placeholder="Saisir mot de passe" required></td>
        </tr>
        <tr>
            <td colspan="2"><button class="btn btn-primary my-2 my-sm-0" type="submit">Ok</button></td>
        </tr>
        <tr>
            <td colspan="2" class="password"><a href="./index.php?action=forgotten">Mot de passe oublié ?</a></td>
        </tr>
    </table>
    </form>
</fieldset>