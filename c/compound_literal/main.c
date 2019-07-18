#include <stdio.h>

typedef struct {
    int a;
    int b;
} t_foo;

void func(t_foo);

int main () {
    // 複合リテラル
    // 構造体を関数に渡す際に, ANSI Cでは一時的な変数を用意する必要があったが, C99からはリテラルを作れるようになった
    func((t_foo){.a = 334, .b = 334});

    return 0;
}

void func(t_foo foo) {
    printf("%d\n", foo.a);
    printf("%d\n", foo.b);
}