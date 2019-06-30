#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[256] = "foo";
    char s2[] = "bar";

    // 文字列の連結を行う(制限付き)
    // strncat(連結先, 連結元, 連結先のサイズ)
    strncat(s1, s2, sizeof(s1) - sizeof(s2) - 1);

    printf("%s\n", s1);

    char s3[7] = "baz";
    strncat(s3, s2, sizeof(s3) - sizeof(s2) - 1);
    printf("%s\n", s3);

    return 0;
}