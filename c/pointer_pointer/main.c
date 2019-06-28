#include <stdio.h>

int main(int argc, char *argv[]) {
    int ary[] = { 1, 1, 2, 3, 5 };
    int *p = ary;
    // ダブルポインタ
    int **pd = &p;
    // トリプルポインタ
    int ***pt = &pd;

    // 以下はどれも配列aryのアドレスを指す
    printf("%p\n", ary);
    printf("%p\n", p);
    printf("%p\n", *pd);
    printf("%p\n\n", **pt);

    // 以下はどれもポインタ変数pのアドレスを指す
    printf("%p\n", &p);
    printf("%p\n", pd);
    printf("%p\n\n", *pt);

    // 間接演算子(*)の増減によって参照するアドレスを辿ることができる

    return 0;
}