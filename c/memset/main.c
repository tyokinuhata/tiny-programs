#include <stdio.h>
#include <stdlib.h>
// memset関数を使用するのに必要
#include <string.h>

int main(int argc, char *argv[]) {
    char *p = malloc(sizeof(int) * 8);

    // memset関数
    // メモリ領域を埋める
    // memset(メモリ領域, 埋めるバイト, サイズ)
    memset(p, 0, sizeof(int) * 8);

    for (int i = 0; i < 8; i++) {
        printf("%d\n", p[i]);
    }

    return 0;
}