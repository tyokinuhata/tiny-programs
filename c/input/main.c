#include <stdio.h>

int main () {

    // scanf
    // バッファオーバーフローを起こしやすい関数の一つ
    char s1[10];
    scanf("%s", s1);
    printf("%s\n", s1);

    // gets
    // バッファオーバーフローを起こしやすい関数の一つ
    // C11で削除された
    // char s2[10];
    // gets(s2);
    // printf("%s\n", s2);

    // 基本的にはfgetsを使用する
    // scanfでも頑張ればバッファオーバーフローを回避できる

    return 0;
}