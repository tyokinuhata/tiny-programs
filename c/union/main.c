#include <stdio.h>

// 共用体
// 構造体との違いはそれぞれのメンバ変数のメモリ空間が共有されるところ
// 共用体のサイズは一番大きなサイズのメンバ変数となる

// 定義
union tag_u {
    int n[4];
    char s[14];
};

int main(int argc, char *argv[]) {
    // 宣言
    union tag_u u;

    char s[] = "hello, world!";

    int i;
    for (i = 0; s[i] != '\0'; i++) u.s[i] = s[i];
    u.s[i] = s[i];

    printf("%s\n", u.s);
    // n[]には何も代入していないが数値が表示される
    printf("%d %d %d %d\n", u.n[0], u.n[1], u.n[2], u.n[3]);

    return 0;
}