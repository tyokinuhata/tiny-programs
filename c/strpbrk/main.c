#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "hello, world!";

    // strpbrk
    // 文字列の検索(複数)
    // strpbrk(検索対象文字列, 検索文字(複数))
    // 最初に「検索文字」が現れた位置へのポインタを返す
    // 見つからない場合はNULLを返す
    char *s2 = strpbrk(s1, ", "); // スペース or カンマ

    printf("%s\n", s2);

    return 0;
}