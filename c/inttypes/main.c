#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
    uint32_t a = 31;

    // ８進数
    printf("%" PRIo32 "\n", a); // 37
    // 符号無し10進数
    printf("%" PRIu32 "\n", a); // 31
    // 16進数(小文字)
    printf("%" PRIx32 "\n", a); // 1f
    // 16進数(大文字)
    printf("%" PRIX32 "\n", a); // 1F
}