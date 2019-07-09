#include <stdio.h>

void read_only(const int foo, const int *bar, int * const baz, const int * const qux);

int main (int argc, char *argv[]) {
    // const指定子
    // 記憶クラス指定子の一つ
    // 初期値以外から変更しようとするとコンパイルエラーとなる
    const int n = 0;
    // n = 334;

    return 0;
}

// const int foo ... 呼び出し元から受け取った値を読み出し専用にする
// const int *bar ... barが指し示す先を読み出し専用にする
// int * const baz ... bazそのものを読み出し専用にする
// const int * const qux ... 2と3の複合型
void read_only(const int foo, const int *bar, int * const baz, const int * const qux) {
    bar = NULL;
    // *bar = 334; // エラー

    // baz = NULL; // エラー
    *baz = 334;

    // qux = NULL; // エラー
    // *qux = 334; // エラー
}