#include <stdio.h>

#define N 5

int main() {
    int ary[N] = { 1, 2, 3, 4, 5 };

    // &ary[0]はaryの先頭要素へのポインタ
    int *p1 = &ary[0];
    for (int i = 0; i < N; i++) {
        printf("%d\n", *(p1 + i));
    }

    // aryとするとデフォルトで先頭要素へのポインタが返ってくるのでこう書ける
    int *p2 = ary;
    for (int i = 0; i < N; i++) {
        printf("%d\n", *(p2 + i));
    }

    int *p3 = ary;
    for (int i = 0; i < N; i++) {
        // *(p3 + i)は省略してp3[i]と書ける
        // つまり, 添字演算子[]は配列とは関係がない
        printf("%d\n", p3[i]);
    }

    // わざわざポインタ変数に配列を入れ変える必要はないのでこう書ける
    for (int i = 0; i < N; i++) {
        printf("%d\n", ary[i]);
    }

    return 0;
}