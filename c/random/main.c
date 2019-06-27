#include <stdio.h>
// rand関数・srand関数を使うために必要
#include <stdlib.h>
#include <time.h>

int main (int argc, char *argv[]) {

    // srand関数
    // 乱数の初期化を行う
    srand(time(NULL));

    // rand関数
    // 0 ~ RAND_MAXまでの数値をランダムに生成する
    // RAND_MAXは環境依存だが, 大抵の場合は2,147,483,647
    printf("%d\n", rand());

    return 0;
}