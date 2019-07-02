#include <stdio.h>

int main(int argc, char *argv[]) {
    char s1[256] = "";
    char s2[] = "foo";
    char s3[] = "bar";

    // printf関数は標準出力されてしまうが, snprintfを使えば変数に入れておくことができる
    // snprintf(出力先, 出力先のサイズ, 書式, 変数１, 変数２, ...);
    snprintf(s1, sizeof(s1), "%s%s", s2, s3);

    // 簡略化されたバージョンにsprintf関数もある
    // sprintf(出力先, 書式, 変数１, 変数２, ...)

    printf("%s\n", s1);

    return 0;
}