// プロセスのバックグラウンド実行
#include <stdio.h>
#include <unistd.h>

int main(void) {
    daemon(0, 0);

    printf("hello, world!");

    for (;;)
        ;

    return 0;
}