#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "foo,bar,baz";

    puts(s1);

    // strtok
    // 文字列を区切り文字ごとに分ける
    // strtok(対象文字列, 区切り文字)
    // 戻り値は分けられた文字列(トークン)の先頭アドレス
    // 分解するトークンがなければNULLを返す
    char *token = strtok(s1, ",");
    puts(token); // foo

    while (token != NULL) {
        // 二回目以降に同じ対象文字列に対して適用する場合は第一引数にNULLを渡す
        token = strtok(NULL, ",");
        if (token != NULL) puts(token); // bar baz
    }

    // 元の文字列は破壊される
    puts(s1); // foo

    // C11からはstrtok_s関数も追加された

    return 0;
}