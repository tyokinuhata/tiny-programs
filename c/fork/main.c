#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    puts("Start of parent process.");
    pid_t process_id = fork();
    // エラーの場合
    if (process_id < 0) {
        exit(EXIT_FAILURE);
    }
    // 子プロセスの場合
    else if (process_id == 0) {
        puts("Start of child process.");
        sleep(2);
        puts("End of child process.");
    }
    // 親プロセスの場合
    else {
        sleep(2);
        puts("End of parent process.");
    }
    puts("Called from both.");
}