#include <stdio.h>

int add(int, int);

int main(int argc, char *argv[]) {
    // 関数ポインタ
    // 関数のアドレスを格納できるポインタ変数
    // 戻り値のデータ型 (*変数名)(引数のリスト) の形式で宣言する
    int (*pf)(int, int) = add;

    // 関数のポインタ変数は, 変数名() のように関数として実行できる
    printf("%d\n", pf(1, 1));

    return 0;
}

int add(int a, int b) {
    return a +  b;
}