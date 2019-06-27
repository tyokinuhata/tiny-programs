#include <stdio.h>
// 自作のヘッダファイル
// Cファイルは直接読み込まず, ヘッダファイルを読み込むようにする
// そうすることでCファイルに変更があったことに気づかずその関数を使用したとしてもコンパイラが警告を出してくれる
#include "func.h"

int main(int argc, char *argv[]) {
    int n = add(1, 1);

    printf("%d\n", n);

    return 0;
}