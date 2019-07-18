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

    // ちなみに構造体におけるアロー演算子は, 上記の例でいうと(*pcoord).xのシンタックスシュガーである
    printf("%f\n", (*pcoord).x);
    printf("%f\n", (*pcoord).y);

    // 自己参照構造体
    typedef struct tag_foo {
        // something ...

        // typedefが完了していないのでt_foo型は使えない
        // また, タグのみを宣言した場合, その値は不完全型となりポインタをとることしかできない
        struct tag_foo *foo;
    } t_foo;

    // or

    typedef struct tag_bar t_bar;

    struct tag_bar {
        // something ...
        struct t_bar *bar;
    };

    // 構造体の相互参照
    typedef struct tag_man t_man;

    typedef struct {
        t_man *man;
    } t_woman;

    struct tag_man {
        t_woman *woman;
        // t_woman woman; // t_womanは構造体の中身も定義しているので実体をとることもできる
    };

    // 構造体のネスティング
    typedef struct {
        // something ...
    } t_baz;

    typedef struct {
        // something ...
        t_baz baz;
    } t_qux;

    typedef struct {
        // something ...
        struct tag_corge {
            // something ...
        } t_corge;
    } t_quux;

    typedef struct {
        // something ...
        struct {
            // something ...
        } t_garply;
    } t_grault;

    return 0;
}