<fieldset>
    <h1>Mot de passe oublié</h1>
    <form action="./index.php" method="post">
    <table>
        <?php
            if (isset($_GET['account']) && $_GET['account'] == 'ok') {
                echo('<tr><td colspan="2" class="account_created">*Un mail de réinitialisation a été envoyé.</td></tr>');
            } elseif (isset($_GET['error'])) {
                if ($_GET['error'] == 'empty')
                    echo('<tr><td colspan="2" class="error">*Erreur: le champ doit être rempli.</td></tr>');
                elseif ($_GET['error'] == 'badmail')
                    echo('<tr><td colspan="2" class="error">*Erreur: adresse mail invalide.</td></tr>');
                else
                    echo('<tr><td colspan="2" class="error">*Erreur: problème de serveur, retentez plus tard.</td></tr>');
            }
        ?>
        <input type="hidden" name="action" value="forgottenchecker">
        <tr>
            <td>Votre adresse mail:</td>
            <td><input type="mail" name="mail" placeholder="Saisir email" autofocus></td>
        </tr>
        <tr>
            <td colspan="2"><button class="btn btn-primary my-2 my-sm-0" type="submit">Ok</button></td>
        </tr>
    </table>
    </form>
</fieldset>