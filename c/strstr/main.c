#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "hello, world!";

    // strpbrk
    // 文字列の検索
    // 文字列の中から文字列を検索する(strchrやstrpbrkのように一文字にヒットするものではない)
    // strstr(検索対象文字列, 検索文字列)
    // 最初に「検索文字列」が現れた位置へのポインタを返す
    // 見つからない場合はNULLを返す
    char *s2 = strpbrk(s1, ", ");

    printf("%s\n", s2);

    return 0;
}