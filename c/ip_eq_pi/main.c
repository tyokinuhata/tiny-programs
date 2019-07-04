#include <stdio.h>

#define N 5

int main() {
    int ary[] = { 1, 2, 3, 4, 5 };
    int *p = ary;

    for (int i = 0; i < N; i++) {
        printf("%d\n", *(p + i));
        // pとiを入れ替えても当然結果は同じ
        printf("%d\n", *(i + p));
    }

    for (int i = 0; i < N; i++) {
        // p[i]は*(p + i)の糖衣構文なので
        printf("%d\n", p[i]);
        // これもpとiを入れ替えることができる
        printf("%d\n", i[p]);
    }

    return 0;
}