#include <stdio.h>

int main() {
    // 定義済みマクロのサンプル

    // ファイル名の表示
    puts(__FILE__);

    // 行番号の表示
    printf("%d\n", __LINE__);

    // 関数名の表示
    // C99で追加
    // 厳密にはマクロではなく事前定義識別子
    puts(__func__);
}