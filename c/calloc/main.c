#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *p;

    // calloc関数
    // 配列としてメモリを取得するのを前提とした関数
    // calloc(要素数, １要素あたりに必要なサイズ(バイト))
    p = calloc(16, 4);

    return 0;
}