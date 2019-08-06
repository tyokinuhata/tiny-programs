#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // getppid関数
    // 親プロセスのプロセスIDを取得する
    printf("%d\n", getppid());

    return 0;
}