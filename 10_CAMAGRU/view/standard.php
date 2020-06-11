<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <link rel="stylesheet" href="./public/css/style.css">
    <title><?= $title ?></title>
</head>
<body>
    <?php
        require_once('./view/menu.php');
        echo('<div class="container-fluid" id="content">');
        echo($content);
        echo('</div>');
    ?>
    <script type="text/javascript">
        document.getElementById("content").style.display = "flex";
    </script>
    <script>
        function myFunction() {
            var x = document.getElementById("responsive_nav");
            if (x.className === "responsive_nav") {
                x.className += " responsive";
            } else {
                x.className = "responsive_nav";
            }
        }
    </script>
    <script>
        let i = 0;
        document.querySelector("#search_input").addEventListener('keyup', function() {
            this.value += 'H';
            i++;
            this.setSelectionRange(i, i);
        });
    </script>
</body>
</html>