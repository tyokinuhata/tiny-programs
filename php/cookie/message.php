<?php

$user_id = $_POST['user_id'];
$password = $_POST['password'];

// Set-Cookieヘッダにセットして返す
setcookie('user_id', $user_id, time() + 60 * 60 * 24 * 14);

?>

<!DOCTYPE html>
<html lang="ja">
    <head>
        <meta charset="UTF-8">
        <title>Cookie</title>
    </head>
    <body>
        <p>User ID: <?= $user_id ?></p>
        <p>Login successfull!</p>
        <a href="./login.php">< Back</a>
    </body>
</html>