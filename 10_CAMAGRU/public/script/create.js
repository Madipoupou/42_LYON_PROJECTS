(function () {
    var width = 320;    // We will scale the photo width to this
    var height = 240;     // This will be computed based on the input stream
    var streaming = false;
    var video = null;
    var canvas = null;
    var photo = null;
    var startbutton = null;
    var capturebutton = null;

    function startup() {
        video = document.getElementById('video');
        canvas = document.getElementById('canvas');
        photo = document.getElementById('photo');
        startbutton = document.getElementById('startbutton');

        navigator.mediaDevices.getUserMedia({ video: true, audio: false })
            .then(function (stream) {
                video.srcObject = stream;
                video.play();
            })
            .catch(function (err) {
                console.log("An error occurred! " + err);
            });

        video.addEventListener('canplay', function (ev) {
            if (!streaming) {
                //height = video.videoHeight / (video.videoWidth/width);

                video.setAttribute('width', width);
                video.setAttribute('height', height);
                canvas.setAttribute('width', width);
                canvas.setAttribute('height', height);
                streaming = true;
            }
        }, false);

        startbutton.addEventListener('click', function (ev) {
            // Video replace vars
            let video = document.querySelector('#video');
            let video_replace = document.querySelector('#video_replace');
            let video_replace_image = document.querySelector('#video_replace_image');

            // Dealing with case of unselected superposition
            let video_overlay = document.querySelector('#video_overlay');
            let video_overlay_image = document.querySelector('#video_overlay_image');
            if (video_overlay_image.src[video_overlay_image.src.length - 1] !== '#') {
                // Displaying save button
                let saveButton = document.querySelector('#saveButton');
                saveButton.style.visibility = 'visible';

                // Putting the picture in the result div
                if (video.style.display === 'none' && video_replace.style.display === 'block') {
                    let myImg = document.getElementById('photo');
                    myImg.src = video_replace_image.src;
                    document.getElementById('image-tag').value = myImg.src;
                } else {
                    takepicture();
                    ev.preventDefault();
                    let myImg = document.getElementById('photo').src;
                    document.getElementById('image-tag').value = myImg;
                }

                // Putting the overlay on the result div
                let result_overlay = document.querySelector('#result_overlay');
                let result_overlay_image = document.querySelector('#result_overlay_image');
                let overlay_input = document.querySelector('#overlay_input');
                let image_title_array = video_overlay_image.src.split('/');
                let image_title = image_title_array[image_title_array.length - 1];

                if (video_overlay.style.display !== 'none') {
                    result_overlay.style.display = 'flex';
                    result_overlay_image.src = video_overlay_image.src;
                    overlay_input.value = image_title;
                }
            }
        }, false);

        clearphoto();
    }

    function clearphoto() {
        var context = canvas.getContext('2d');
        context.fillStyle = "#AAA";
        context.fillRect(0, 0, canvas.width, canvas.height);

        var data = canvas.toDataURL('image/png');
        photo.setAttribute('src', data);
    }

    function takepicture() {
        var context = canvas.getContext('2d');
        if (width && height) {
            canvas.width = width;
            canvas.height = height;
            context.drawImage(video, 0, 0, width, height);
            var data = canvas.toDataURL('image/png');
            photo.setAttribute('src', data);
        } else {
            clearphoto();
        }
    }
    window.addEventListener('load', startup, false);
})();

function addPicture(image) {
    // Creating needed vars
    let image_title_arr = image.src.split('/');
    let image_title = image_title_arr[image_title_arr.length - 1];
    let video_overlay = document.querySelector('#video_overlay');
    let video_overlay_image = document.querySelector('#video_overlay_image');
    let video_overlay_title = video_overlay_image.src.split('/');
    let video_overlay_title_final = video_overlay_title[video_overlay_title.length - 1];

    // Managing the overlay
    if (video_overlay_title_final === image_title) {
        video_overlay.style.display = 'none';
        video_overlay_image.src = '#';
    } else {
        video_overlay.style.display = 'flex';
        video_overlay_image.src = './public/cliparts/' + image_title;
    }
}

function deletePicture(photo) {
    let url = './index.php';
    let formData = new FormData();
    let photoNameSrc = photo.src.split('/');
    let photoName = photoNameSrc[photoNameSrc.length - 1];

    formData.append('action', 'deletePicture');
    formData.append('photoName', photoName);

    fetch(url, { method: 'POST', body: formData })
        .then(response => response.text())
        .then(res => document.location.reload(true))
        .catch(error => console.log(error));
}