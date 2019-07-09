#include <stdio.h>
// assert関数を使うために必要
#include <assert.h>

int main(void) {

    // assert(条件式) の形式
    // 条件式が偽の場合にメッセージを出力してプログラムを強制終了する
    assert(1);

    // 出力される
    puts("hello, world!");

    assert(0);

    // 出力されない
    puts("hello, world!");

    return 0;
}