// Cコンパイラのバージョン確認を行うサンプル
// コンパイルエラー ... C99未満
// 199901 ... C99対応
// 201112 ... C11対応
#include <stdio.h>

int main(void) {
    printf("%1ld\n", __STDC_VERSION__);
    return 0;
}