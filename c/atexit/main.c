#include <stdio.h>
// atexit関数を使うために必要
#include <stdlib.h>

void func(void);

int main () {
    // プログラムが正常終了した場合に呼び出す関数を登録する関数
    atexit(func);

    return 0;
}

void func() {
    puts("hello, world!");
}