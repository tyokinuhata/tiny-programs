#include <stdio.h>
// malloc関数を使用するために必要
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *s;

    // malloc関数
    // Memory Allocateの略称
    // メモリを確保する関数
    // malloc(サイズ(バイト単位))
    // 戻り値はvoidポインタ
    s = malloc(14);

    return 0;
}