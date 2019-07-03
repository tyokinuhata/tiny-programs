#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[256] = "hello, world!";
    char s2[256];

    // memcpy関数
    // メモリ領域を別のメモリ領域へコピーする
    // \0を見つけても指定サイズ分コピーするstrncpy関数
    // memcpy(コピー先, コピー元, サイズ)
    memcpy(s2, s1, sizeof(s2));

    printf("%s\n", s1);
    printf("%s\n", s2);

    return 0;
}