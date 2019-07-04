#include <stdio.h>

int main(int argc, char *argv[]) {
    int n = 334;
    printf("%d\n", n);
    printf("%p\n", &n);

    // ポインタ変数
    // 変数のアドレスを格納することができる型
    // 宣言のときの*や[]は演算子の*や[]とは別物
    // 宣言の際の*, [] ... 区切り子
    // 演算子の*, [] ... C99からは区切り子の一種(面倒くさい)
    int *np = &n;
    // 間接演算子
    // ポインタ変数を宣言する際の*とは別物
    // ポインタ変数に格納されているアドレスに格納されている値を取得する
    printf("%d\n", *np);
    printf("%p\n", np);

    int ary[] = { 1, 1, 2, 3, 5 };
    int *pary = ary;

    for (int i = 0; i < sizeof(ary) / sizeof(int); i++) {
        printf("%d\n", *pary++);
    }

    return 0;
}