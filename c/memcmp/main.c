#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int a = 334;
    int b = 334;

    // memcmp関数
    // メモリ領域の内容を比較する
    // memcmp(領域１, 領域２, サイズ)
    // 等しい場合は0, 領域１ > 領域２の場合は正の数, 領域１ < 領域２の場合は負の数
    printf("%d\n", memcmp(&a, &b, sizeof(int)) == 0);

    return 0;
}