#include <stdio.h>

int main () {
    // 整数拡張(integer promotion)
    // intよりもサイズの小さな型は式の中ではintに拡張されるという機能

    unsigned int n = 0xffffffff;
    unsigned char c = 0xff;

    // intの最大値にさらに数値を加算すると, ラップアラウンドされ, 0に戻る
    if (n + 10 < 10) {
        puts("n + 10 < 10"); // こちら側が出力
    } else {
        puts("n + 10 >= 10");
    }

    // charの最大値にさらに数値を加算しても, intに拡張されるため, ラップアラウンドされない
    if (c + 10 < 10) {
        puts("c + 10 < 10");
    } else {
        puts("c + 10 >= 10"); // こちら側が出力
    }

    return 0;
}