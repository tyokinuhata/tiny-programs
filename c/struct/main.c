#include <stdio.h>

// 構造体
// 意味のあるひとまとまりのデータをデータ型として定義する仕組み

// 構造体の定義
// struct 構造体タグ名 { メンバ変数 }; といった形式で定義する
struct tag_coord {
    double x;
    double y;
};

// ちなみに構造体名は可能な限り省略したほうが良いとされているので(そういうスタイルもあるということ),
typedef struct {
    // somethig ...
} t_foo;
// というふうにtypedefで定義してしまったほうが好ましい

int main(int argc, char *argv[]) {
    // 宣言
    // struct 構造体タグ名 変数名; といった形式で宣言する
    struct tag_coord coord;

    // 代入
    // ドット演算子を使用する
    coord.x = 1.14514;
    coord.y = 1.919;

    printf("%f\n", coord.x);
    printf("%f\n", coord.y);

    struct tag_coord *pcoord = &coord;

    // 構造体のポインタの場合, ドット演算子ではなくアロー演算子を使用する
    printf("%f\n", pcoord->x);
    printf("%f\n", pcoord->y);

    return 0;
}