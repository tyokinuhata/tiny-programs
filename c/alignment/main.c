#include <stdio.h>
#include <stdint.h>

struct data {
    uint8_t a;
    uint16_t b;
    uint64_t c;
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
}