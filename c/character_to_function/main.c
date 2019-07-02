#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    char c1 = 'a';

    printf("%c\n", c1);
    // 大文字に変換する
    printf("%c\n", toupper(c1));

    char c2 = 'B';
    printf("%c\n", c2);
    // 小文字に変換する
    printf("%c\n", tolower(c2));

    return 0;
}