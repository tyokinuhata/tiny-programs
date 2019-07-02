#include <stdio.h>
// 文字関数を使うために必要
#include <ctype.h>

int main(int argc, char *argv[]) {
    // 文字関数
    // １文字(char型)に対して適用される関数

    int c = 0;

    while (c < 256) {
        printf("%c ", c++);

        // 表示可能な文字かどうか
        if (isprint(c)) {
            printf("%c ", c);
        }
        // 空白・改行かどうか
        else if (isspace(c)) {
            printf(". ");
        }
        else {
            printf("%02x", c);
        }

        if (c % 16 == 0) puts("");
    }

    return 0;
}