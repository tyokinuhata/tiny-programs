#include <stdio.h>

int main (int argc, char *argv[]) {
    int a, b, c;

    // カンマ演算子
    // 複数の文を一行で書くための演算子
    // 式の値としては最後の文のものを持つ(つまり3)
    int n = (a = 1, b = 2, c = 3);

    printf("%d\n", n);

    return 0;
}