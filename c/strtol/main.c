#include <stdio.h>
// strtol関数を使うために必要
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char s[7] = "114514";

    // strtol関数
    // 文字列を数値(long型)に変換する関数
    // 引数には 文字列, 最後の文字の格納先, 基数 の順で指定する
    long n = strtol(s, NULL, 10);

    printf("%ld\n", n);

    return 0;
}