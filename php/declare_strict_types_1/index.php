<?php

// 厳密な型宣言の有効化
// 型が一致しない場合に, PHP Fatal Errorを出力してくれる
// ただし, ファイル単位で宣言が必要
// また, これを宣言していない場合でも, PHP Noticeは出力される(環境による？)
declare(strict_types=1);

function plus (int $a, int $b)
{
    return $a + $b;
}

echo plus('1a', '1b');