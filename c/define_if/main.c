#define ENV 1

// if命令を使うと処理ではなくソースコード自体を分岐させることができる
// Windows用/Mac用のように異なる環境のコードを用意しておいて分岐させるといった使い方ができる
// gcc -E -ENV=1 main.c のように指定する
#if ENV == 1
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("hello, world!\n");
    return 0;
}
#else

#endif

