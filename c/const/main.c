#include <stdio.h>

int main (int argc, char *argv[]) {
    // const指定子
    // 記憶クラス指定子の一つ
    // 初期値以外から変更しようとするとコンパイルエラーとなる
    const int n = 0;
    n = 334;

    return 0;
}