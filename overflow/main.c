#include <stdio.h>

int main (int argc, char *argv[]) {
    int int_max = 0x7FFFFFFF;

    // オーバーフローする
    int int_overflow = 0x7FFFFFFF + 1;

    printf("%d\n", int_max);
    printf("%d\n", int_overflow);

    return 0;
}