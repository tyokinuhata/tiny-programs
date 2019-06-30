#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[256] = "foo";
    char s2[] = "bar";

    // 文字列の連結を行う
    // strcat(連結先, 連結元)
    // NULLチェックやサイズチェックは行われないので注意する
    strcat(s1, s2);

    printf("%s\n", s1);

    return 0;
}