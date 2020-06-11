<div class="comment_main">
    <div class="comment_img">
        <?= $photo_html ?>
    </div>
    <div class="comment_comments">
        <div class="comments_display">
            <?= $comments_html ?>
        </div>
        <div class="comments_write">
            <form action="./index.php" method="POST">
                <label for="textComment">Votre commentaire:</label>
                <textarea rows="3" class="textComment" id="textComment" type="text" name="textComment" placeholder="Saisir commentaire"></textarea>
                <input type="hidden" name="idPhoto" value="<?= $idPhoto ?>">
                <input type="hidden" name="action" value="commentchecker">
                <button class="btn btn-primary my-2 my-sm-0" type="submit">Valider</button>
            </form>
        </div>
    </div>
</div>