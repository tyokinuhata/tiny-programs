#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "hello, world!";

    // strchr
    // 文字列の検索
    // strchr(検索対象文字列, 検索文字)
    // 最初に「検索文字」が現れた位置へのポインタを返す
    // 見つからない場合はNULLを返す
    char *s2 = strchr(s1, 'w');

    printf("%s\n", s2);

    return 0;
}