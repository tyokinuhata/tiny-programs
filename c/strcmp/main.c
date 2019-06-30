#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char s1[] = "foo";
    char s2[] = "bar";
    char s3[] = "bar";

    // strcmp
    // strcmp(文字列１, 文字列２)
    // 文字列１が文字列２よりも大きければ正の数
    // 文字列１が文字列２と等しければ0
    // 文字列１が文字列２よりも小さければ負の数
    // が返される
    // 大小比較は辞書順で行われる
    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", strcmp(s2, s3));

    return 0;
}