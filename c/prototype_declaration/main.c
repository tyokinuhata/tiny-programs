#include <stdio.h>

// プロトタイプ宣言
// C90 ... なくても良い
// C99 ... 必須
// 関数名・関数の引数の数と型・関数の戻り値を定義しておくための構文
// Cでは呼び出される関数が呼び出す関数よりも前で定義されている必要がある
// また, 関数の呼び出し時に引数の数や型が違っていればコンパイルエラーにしてくれる
int add (int, int);

int main (int argc, char *argv[]) {
    int answer = add(1, 1);

    printf("%d\n", answer);

    return 0;
}

int add (int a, int b) {
    return a + b;
}