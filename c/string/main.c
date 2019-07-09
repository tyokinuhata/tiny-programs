#include <stdio.h>

int main() {
    // 文字列リテラルはcharの配列と同じ
    char s1[] = "hello, world!";

    // つまり, 以下と同じ
    char s2[] = { 'h', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0' };

    printf("%s\n", s1);
    printf("%s\n", s2);

    // 内部的には文字列をメモリに格納し, それをコピーしたものをcharの配列に代入している

    // 以下の例の場合は, 文字列をメモリに格納し, そのアドレスをs3が持っているため, 内部的な挙動は配列とポインタで少し違う
    char *s3 = "hello, world!";

    printf("%p\n", s1); // 0x7ffeeebc48ca
    printf("%p\n", s2); // 0x7ffeeebc48b
    printf("%p\n", s3); // 0x10103bf9c <- 離れている

    return 0;
}