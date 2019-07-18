#include <stdio.h>

typedef struct tag_foo {
    struct {
        int hoge;
    } s;

    // 無名構造体
    // C11から追加
    struct {
        int hoge;
    };
} t_foo;

int main () {
    t_foo foo1;
    // sが邪魔
    foo1.s.hoge = 334;
    printf("%d\n", foo1.s.hoge);

    t_foo foo2;
    foo2.hoge = 334;
    printf("%d\n", foo2.hoge);

    return 0;
}