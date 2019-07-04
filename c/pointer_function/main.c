#include <stdio.h>

void override(int *);

int main(int argc, char *argv[]) {
    int a = 1;
    printf("%d\n", a);

    // 変数aのアドレスを渡す
    override(&a);
    printf("%d\n", a);

    return 0;
}

// 引数のint型のポインタ変数でアドレスを受け取る
void override(int *a) {
    // ポインタ変数の参照先の値に2を代入する
    // つまり呼び出し元の変数aが書き換わる
    // 戻り値で返せる値は１つだけだが, 呼び出し元の変数はいくらでも書き換えられる
    *a = 2;
}

// 引数で配列を宣言してもポインタに読み替えられる
// 配列を値渡しすることはできない
void override2(int a[]) {
    *a = 3;
}

// 要素数を記述していても無視される
void override3(int a[10]) {
    *a = 4;
}