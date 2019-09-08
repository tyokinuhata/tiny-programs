<?php
// php -S localhost:8080 -t ./

// Cookieがあるかの判別
if (isset($_COOKIE['user_id'])) {
    $user_id = $_COOKIE['user_id'];
} else {
    $user_id = '';
}

?>

<!DOCTYPE html>
<html lang="ja">
    <head>
        <meta charset="utf-8">
        <title>Cookie</title>
    </head>
    <body>
        <form action="./message.php" method="post">
            <dl>
                <dt>User ID: </dt>
                <dd>
                    <input type="text" name="user_id" value="<?= $user_id ?>">
                </dd>

                <dt>Password: </dt>
                <dd>
                    <input type="password" name="password">
                </dd>
            </dl>

            <button type="submit">Login</button>
        </form>
    </body>
</html>