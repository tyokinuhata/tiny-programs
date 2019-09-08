<?php

// Cookieの保存
$user_id = $_POST['user_id'];
$password = $_POST['password'];

setcookie('user_id', $user_id, time() + 60 * 60 * 24 * 14);

?>

<!DOCTYPE html>
<html lang="ja">
    <head>
        <meta charset="UTF-8">
        <title>Cookie</title>
    </head>
    <body>
        <p>Login successfull!</p>
        <a href="./login.php">< Back</a>
    </body>
</html>