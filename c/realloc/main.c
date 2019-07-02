#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *s1, *s2;

    s1 = malloc(14);
    printf("%p\n", s1);

    strncpy(s1, "hello, world!", 13);
    printf("%s\n", s1);

    // realloc関数
    // realloc(拡張したいポインタ, 拡張後のサイズ)
    // 戻り値は拡張されたメモリ領域
    // 以前に確保したメモリ領域から拡張できるのであれば拡張し, できなければ別のメモリ領域を確保する
    // また, 失敗時にはNULLが返る
    s2 = realloc(s1, 32);
    printf("%p\n", s2);

    s1 = s2;
    printf("%p\n", s1);
    printf("%s\n", s1);

    free(s1);

    return 0;
}