<?php

session_start();

$user_id = $_POST['user_id'];
$password = $_POST['password'];

// セッションに保存
$_SESSION['user_id'] = $user_id;

?>

<!DOCTYPE html>
<html lang="ja">
    <head>
        <meta charset="UTF-8">
        <title>Cookie</title>
    </head>
    <body>
        <p>User ID: <?= $_SESSION['user_id'] ?></p>
        <p>Login successfull!</p>
        <a href="./login.php">< Back</a>
        <a href="./page.php">> Page</a>
        <a href="./logout.php">> Logout</a>
    </body>
</html>