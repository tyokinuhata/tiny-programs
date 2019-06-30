#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "bar";
    char s2[] = "baz";

    // strncmp
    // 第三引数で何文字目までを比較するのかを指定できるのが特徴
    // strncmp(文字列１, 文字列２, 比較する数)
    printf("%d\n", strncmp(s1, s2, 2));

    return 0;
}