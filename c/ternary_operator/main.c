// 三項演算子(条件演算子)

#include <stdio.h>

int main ()
{
    int a = 1, b = 2;

    // if文で記述した場合
    int x;
    if (a)  x = a;
    else    x = b;

    // 三項演算子(条件演算子)で記述した場合
    int y = a ? a : b;

    // さらに省略形(エルビス演算子)
    // これはgccの拡張機能
    int z = a ?: b;

    printf("%d %d %d\n", x, y, z);
}