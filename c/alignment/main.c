#include <stdio.h>
#include <stdint.h>

struct data {
    uint8_t a;
    uint16_t b;
    uint64_t c;
};

struct data2 {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
};

struct data3 {
    uint8_t a;
    uint16_t b;
    uint32_t c;
    uint64_t d;
    uint8_t e;
};

int main()
{
    struct data d;

    // 1byte + 2byte + 8byte = 11byte
    // になると思いきや
    // 4byte + 4byte + 8byte = 16byte
    // になる
    // これがアラインメント
    // メモリアクセスの制限や効率化(各フィールドが４の倍数のアドレスに配置されることが望ましい)のためにパディング(詰め物)がされる
    // x86系のアーキテクチャはアラインメントされていないデータへアクセスしても問題ない
    printf("%zu\n", sizeof(d));

    printf("%zu\t%p\t%lu\n", sizeof(d.a), &d.a, (uintptr_t)&d.a - (uintptr_t)&d);
    printf("%zu\t%p\t%lu\n", sizeof(d.b), &d.b, (uintptr_t)&d.b - (uintptr_t)&d);
    printf("%zu\t%p\t%lu\n", sizeof(d.c), &d.c, (uintptr_t)&d.c - (uintptr_t)&d);

    //----------

    struct data2 d2;

    // 16byte
    // フィールドを増やしてもサイズが変わらないパターン
    printf("%zu\n", sizeof(d2));

    printf("%zu\t%p\t%lu\n", sizeof(d2.a), &d2.a, (uintptr_t)&d2.a - (uintptr_t)&d2);
    printf("%zu\t%p\t%lu\n", sizeof(d2.b), &d2.b, (uintptr_t)&d2.b - (uintptr_t)&d2);
    printf("%zu\t%p\t%lu\n", sizeof(d2.c), &d2.c, (uintptr_t)&d2.c - (uintptr_t)&d2);
    printf("%zu\t%p\t%lu\n", sizeof(d2.d), &d2.d, (uintptr_t)&d2.d - (uintptr_t)&d2);

    //----------

    struct data3 d3;

    // 24byte
    // 末尾のアラインメント
    // 末尾にもアラインメントが挿入されることはある
    printf("%zu\n", sizeof(d3));

    printf("%zu\t%p\t%lu\n", sizeof(d3.a), &d3.a, (uintptr_t)&d3.a - (uintptr_t)&d3);
    printf("%zu\t%p\t%lu\n", sizeof(d3.b), &d3.b, (uintptr_t)&d3.b - (uintptr_t)&d3);
    printf("%zu\t%p\t%lu\n", sizeof(d3.c), &d3.c, (uintptr_t)&d3.c - (uintptr_t)&d3);
    printf("%zu\t%p\t%lu\n", sizeof(d3.d), &d3.d, (uintptr_t)&d3.d - (uintptr_t)&d3);
    printf("%zu\t%p\t%lu\n", sizeof(d3.d), &d3.d, (uintptr_t)&d3.e - (uintptr_t)&d3);

}