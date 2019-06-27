#include <stdio.h>

int main (int argc, char *argv[]) {
    char s[16];

    // ファイル(ストリーム)から文字列を読み込むための関数
    // 標準ストリーム ... stdin・stdout・stderr
    fgets(s, 16, stdin);

    printf("%s", s);

    return 0;
}