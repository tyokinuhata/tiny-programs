#include <stdio.h>
// offsetofマクロを使用するために必要
#include <stddef.h>

int main () {
    typedef struct {
        int hoge;
        int piyo;
    } t_foo;

    // 構造体メンバが構造体の中で何バイト目に位置するかを返す
    int offset = offsetof(t_foo, piyo);

    printf("%d\n", offset);

    return 0;
}