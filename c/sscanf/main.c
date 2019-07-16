#include <stdio.h>

#define N 256

int main () {
    char s1[] = "hello! 334 hogehogeunko";

    char s2[N] = { '\0' };
    int n;
    char s3[N] = { '\0' };;

    // sscanf関数
    // 指定した文字列から書式文字列に従ってデータを取得する
    // sscanf(対象文字列, 書式文字列, 取得する変数１, 取得する変数２, ...)
    sscanf(s1, "%s %d %s", s2, &n, s3);

    printf("%s, %d, %s\n", s2, n, s3);

    return 0;
}