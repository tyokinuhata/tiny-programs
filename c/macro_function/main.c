#include <stdio.h>

// マクロ関数
// 引数を受け取って置換するdefine命令のこと
#define ADD(a, b) a + b

int main(int argc, char *argv[]) {
    int answer = ADD(1, 1);

    printf("%d\n", answer);

    return 0;
}