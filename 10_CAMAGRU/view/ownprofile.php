<fieldset>
    <h1>Modifier votre profil</h1>
    <form action="./index.php" method="post">
    <table>
        <?php
            if (isset($_GET['account']) && $_GET['account'] == 'ok') {
                echo('<tr><td colspan="2" class="account_created">*Compte mis à jour.</td></tr>');
            } elseif (isset($_GET['error'])) {
                if ($_GET['error'] == 'empty')
                    echo('<tr><td colspan="2" class="error">*Erreur: les champs pseudo et mail doivent être remplis.</td></tr>');
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
        <input type="hidden" name="action" value="ownprofilechecker"
        <tr>
            <td>Votre pseudo:</td>
            <td><input type="text" name="pseudo" value="<?= htmlspecialchars($userInfo['nameUser']) ?>"></td>
        </tr>
        <tr>
            <td>Votre adresse mail:</td>
            <td><input type="mail" name="mail" value="<?= htmlspecialchars($userInfo['mailUser']) ?>"></td>
        </tr>
        <tr>
            <td>Nouveau mot de passe:</td>
            <td><input type="password" name="pwd" placeholder="Saisir mot de passe"></td>
        </tr>
        <tr>
            <td>Confirmez mot de passe:</td>
            <td><input type="password" name="pwd_confirm" placeholder="Confirmer mot de passe"></td>
        </tr>
        <tr>
            <td>Mails de notification:</td>
            <td class="td_radio">
                <div class="custom-control custom-radio radio_div">
                    <input type="radio" class="custom-control-input" id="notif_yes" name="notifStatus" value="1" <?php if ($userInfo['notifStatus']) { echo('checked'); } ?> >
                    <label class="custom-control-label" for="notif_yes">Oui</label>
                </div>
                <div class="custom-control custom-radio radio_div">
                    <input type="radio" class="custom-control-input" id="notif_no" name="notifStatus" value="0" <?php if (!$userInfo['notifStatus']) { echo('checked'); } ?>>
                    <label class="custom-control-label" for="notif_no">Non</label>
                </div>
            </td>
        </tr>
        <tr>
            <td colspan="2"><button class="btn btn-primary my-2 my-sm-0" type="submit">Modifier</button></td>
        </tr>
    </table>
    </form>
</fieldset>