// マクロ関数の丸括弧
// gccの拡張機能

#include <stdio.h>

// これは駄目
// #define ADD(a, b) { a + b; }
// ()で囲むことによって評価結果を受け取ることができるため, 変数に代入できる
#define ADD(a, b) ({ a + b; })

int main ()
{
	int a = 1, b = 2;
	int n = ADD(a, b);
    printf("%d\n", n);
}