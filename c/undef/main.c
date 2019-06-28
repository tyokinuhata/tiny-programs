#include <stdio.h>

// 一度define命令を置くと, 以降の行ではずっと有効になる
#define HOGE 4;

// 何らかの理由で一度define命令で置換したものを無効にする際にはundef命令を使う
#undef HOGE;

int main(int argc, char *argv[]) {
    // undefされているのでコンパイルエラー
    int hoge = HOGE;

    printf("%d\n", 330 + hoge);

    return 0;
}