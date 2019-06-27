#include <stdio.h>

void func() {
    // ローカル変数・自動変数
    // スタックに確保され, 関数から抜けると破棄される
    int count = 0;

    // 静的変数
    // 値を永続的に保持する
    static int static_count = 0;

    printf("%d\n", ++count);
    printf("%d\n", ++static_count);
}

int main (int argc, char *argv[]) {
    func();
    func();
    func();

    return 0;
}