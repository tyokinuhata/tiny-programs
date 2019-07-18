#include <stdio.h>

typedef struct {
    int a;
    int b;
    int c;
    int ary[10];
} t_foo;

int main () {
    // 要素指示子付きの初期化(designated initializer)
    // C99から追加
    // 構造体の一部のメンバを初期化する場合, 初期化するメンバを明示的に指定できる
    // 配列は添字を指定して初期化. その後ろに並んだ数値は添字を指定した要素の続きとして初期化される
    t_foo foo = {.b = 334, .c = 334, {[3] = 3, 3, 4}};

    printf("%d\n", foo.b);
    printf("%d\n", foo.ary[3]);

    return 0;
}