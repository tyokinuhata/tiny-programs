#include <stdio.h>
// 文字列操作系の関数を使用するのに必要
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "hello, world!";
    char s2[14] = "";

    printf("%s\n", s2);

    // 文字列のコピー
    // strcpy(コピー先, コピー元)
    strcpy(s2, s1);

    printf("%s\n", s2);

    // NULLチェックを内部で行っていないので引数にNULLを渡すと異常終了する
    // Segmentation fault
    // strcpy(s2, NULL);

    // サイズのチェックを行わないのでサイズを超えたコピーを行うと異常終了する
    // Abort trap
    // char s3[] = "";
    // strcpy(s3, s1);

    return 0;
}