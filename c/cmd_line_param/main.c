#include <stdio.h>

int main(int argc, char *argv[]) {
    // コマンドライン引数
    // main関数の引数のこと
    // 実行時にコマンドから渡すことができる引数
    // e.g. ./a.out foo bar baz

    // argc
    // コマンドライン引数の数
    printf("%d\n", argc);

    // argv
    // コマンドライン引数の中身
    // 0番目にはファイル名が入っている
    for (int i = 0; i < argc; i++) puts(argv[i]);
}