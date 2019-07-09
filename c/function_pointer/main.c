#include <stdio.h>

int add(int, int);

int main(int argc, char *argv[]) {
    // 関数ポインタ
    // 関数のアドレスを格納できるポインタ変数
    // 戻り値のデータ型 (*変数名)(引数のリスト) の形式で宣言する
    int (*pf)(int, int) = add;

    // 関数のポインタ変数は, 変数名() のように関数として実行できる
    printf("%d\n", pf(1, 1));

    // 関数は式の中では「関数へのポインタ」に読み替えられる
    // 関数のポインタに対して間接演算子を適用すると, 一旦「関数」になるが, 即座に「関数へのポインタ」に変換される
    // そのため, 以下のコードは問題なく動作する
    (**********printf)("hello, world!\n");

    return 0;
}

int add(int a, int b) {
    return a +  b;
}