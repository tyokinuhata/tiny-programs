#include <stdio.h>

struct tag_bf {
    // ビットフィールド
    // 通常の変数はバイト単位のサイズでしか宣言できないが, 構造体ではビット単位の変数を宣言することができる
    // unsignedかsignedしか指定することができない
    // ビットフィールドは処理系依存の部分がある他, 現在はメモリが潤沢にあるため, 組込みシステムなどのメモリが限られた環境での使用に留める

    // 0か1のみ保持できる
    unsigned bin: 1;
    // 0 ~ 15までを保持できる
    unsigned half_byte: 4;
};

int main(int argc, char *argv[]) {
    struct tag_bf bf;

    bf.bin = 1;
    bf.half_byte = 15;

    printf("%d\n", bf.bin);
    printf("%d\n", bf.half_byte);

    bf.bin = 2;
    bf.half_byte = 16;

    // 範囲を超えているので警告が出る
    printf("%d\n", bf.bin);
    printf("%d\n", bf.half_byte);

    return 0;
}