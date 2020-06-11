<div class="create">
    <div class="create_left">
        <div class="create_left_top">
            <div class="camera">
                <table>
                    <tr><td colspan="2">
                        <video id="video"></video>
                        <div id="video_replace" style="display: none;"><img src="#" alt="#" id="video_replace_image" style="width: 320px;height: 240px;" /></div>
                        <div id="video_overlay" style="display: none;"><img src="#" alt="#" id="video_overlay_image" /></div>
                    </td></tr>
                    <tr>
                        <td align="center"><button class="btn btn-primary my-2 my-sm-0" id="startbutton">Capturer</button></td>
                        <td align="center">
                            <label for="file" class="btn btn-primary label-file">Choisir un fichier</label>
                            <input id="file" class="input-file" type="file">
                        </td>
                        
                    </tr>
                </table>
                <canvas id="canvas"></canvas>
            </div>
            <div class="output">
                <table>
                    <tr><td class="capture">
                        <img id="photo" alt="The screen capture will appear in this box.">
                        <div id="result_overlay" style="display: none;"><img src="#" alt="#" id="result_overlay_image" /></div>
                    </td></tr>
                    <tr><td align="center">
                        <form action="./index.php" method="POST">
                            <input type="hidden" name="image" id="image-tag">
                            <input type="hidden" name="overlay" value="none" id="overlay_input">
                            <input type="hidden" name="action" value="createchecker">
                            <button id="saveButton" class="btn btn-primary my-2 my-sm-0" type="submit" style="visibility:hidden;">Sauvegarder</button>
                        </form>
                    </td></tr>
                </table>
            </div>
        </div>
        <div class="create_left_bottom">
            <div class="outside_objects">
                <div class="objects">
                    <?= $cliparts ?>
                </div>
            </div> 
        </div>
    </div>
    <div class="create_right">
        <div class="outside_user_gallery">
            <div class="user_gallery">
                <?= $user_gallery ?>
                <?php print_r($temp); ?>
            </div>
        </div>
       
    </div>
</div>

<script type="text/javascript" src="./public/script/create.js"></script>
<script>
    document.querySelector('#file').addEventListener('change', function() {
        let video = document.querySelector('#video');
        let video_replace = document.querySelector('#video_replace');
        let video_replace_image = document.querySelector('#video_replace_image');
        let allowedTypes = ['png'];

        // function to extract file data
        function createThumbnail(file) {    
            var reader = new FileReader();

            reader.addEventListener('load', function() {    
                video.style.display = 'none';
                video_replace.style.display = 'block';
                video_replace_image.src = this.result;
            });
            reader.readAsDataURL(file);
        }

        imgType = this.files[0].name.split('.');
        imgType = imgType[imgType.length - 1].toLowerCase();
        if (allowedTypes.indexOf(imgType) != -1) {
            createThumbnail(this.files[0]);
        } else {
            alert('Format supporté: png');
        }

    });
</script>