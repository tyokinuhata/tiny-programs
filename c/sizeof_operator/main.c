#include <stdio.h>

int main (int argc, char *argv[]) {

    // sizeof演算子
    // データ型のサイズ(バイト)を返す
    // 関数ではないことに注意

    // 4バイト
    // 数値で特に型の指定がない場合, CPUが一番高速に動作できるint型を使う
    printf("%zu\n", sizeof 1);

    // 14バイト(末尾の\0もカウントされる)
    printf("%zu\n", sizeof "hello, world!");

    int n = 334;
    printf("%zu\n", sizeof n);

    // データ型を指定する場合は()を付ける必要がある
    printf("%zu\n", sizeof(long long));

    return 0;
}