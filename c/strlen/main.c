#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s[] = "hello, world!";
    size_t len;

    // 文字列の長さを求める関数
    // size_t型で返ってくる
    len = strlen(s);

    printf("%zu\n", len);

    return 0;
}