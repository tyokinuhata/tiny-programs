// アンパック構造体
// アラインメントを挿入しない構造体を定義できる

#include <stdio.h>
#include <stdint.h>

// gccによる拡張を使うパターン
struct data {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
    uint8_t e;
} __attribute__((packed));

// プラグマ演算子を使うパターン
#pragma pack(push)
#pragma pack(1)
struct data2 {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
    uint8_t e;
};
#pragma pack(pop)

int main()
{
    struct data d;
    struct data2 d2;

    // 24byteになるところが16byteになっている
    printf("%zu\n", sizeof(d));
    printf("%zu\n", sizeof(d2));
}