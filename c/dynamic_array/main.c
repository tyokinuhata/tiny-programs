#include <stdio.h>
#include <stdlib.h>

int main () {

    // 動的配列
    // VLA(可変長配列とは別)
    int *ary = malloc(sizeof(int) * 10);

    for (int i = 0; i < 10; i++) {
        ary[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", ary[i]);
    }

    return 0;
}