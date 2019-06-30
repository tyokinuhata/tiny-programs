#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "hello, world!";
    char s2[14] = "";

    printf("%s\n", s2);

    // 文字列のコピー(制限付き)
    // strncpy(コピー先, コピー元, コピー先のサイズ)
    strncpy(s2, s1, sizeof s2);

    printf("%s\n", s2);

    char s3[4] = "";
    // strncpyは指定された限界までコピーするため, \0を入れてくれない
    // そのため予期しない動作となる
    // strncpy(s3, s1, sizeof(s3));
    // -1するとうまくいく
    strncpy(s3, s1, sizeof(s3) - 1);

    printf("%s\n", s3);

    return 0;
}