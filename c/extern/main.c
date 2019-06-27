#include <stdio.h>

// 外部ファイルにあるグローバル変数の読み込み
extern int global;

int main (int argc, char *argv[]) {
    printf("%d\n", global);

    return 0;
}