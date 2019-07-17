#include <stdio.h>
// _Bool型を使うために必要
#include <stdbool.h>

int main () {
    // C99から追加
    // _Bool型
    bool b1 = true;
    bool b2 = false;

    // 数値で指定も可能
    bool b3 = 1;
    bool b4 = 0;

    // 1よりも大きい数の場合は1(true)として扱われる
    bool b5 = 2;
    printf("%d\n", b5); // 1

    return 0;
}