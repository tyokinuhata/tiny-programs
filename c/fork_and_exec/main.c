#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>

static void child();
static void parent(pid_t);

int main ()
{
    pid_t pid = fork();
    if (pid == -1)      err(EXIT_FAILURE, "fork() failed.");
    else if (pid == 0)  child();
    else                parent(pid);
    err(EXIT_FAILURE, "shouldn't reach here.");
}

// 子プロセス
static void child ()
{
    printf("I'm child! my pid is %d.\n", getpid());
    // fflush関数
    // バッファに格納されているデータを吐き出す関数
    // stdinを指定した場合は標準入力バッファ, stdoutを指定した場合は標準出力バッファ
    // int fflash(FILE *fp)
    fflush(stdout);

    char *args[] = { "/bin/echo", "hello", NULL };
    // execve関数
    // プロセスを新規生成する関数
    // 親プロセスから子プロセス生成 -> 子プロセスからプロセスを新規生成 という流れが一般的
    // これはプロセスを新規生成するとそれまでのプロセスが新しいプロセスに置き換わるため
    // int execve(const char *fileName, char *const argv[], char *const envp[])
    execve("/bin/echo", args, NULL);

    err(EXIT_FAILURE, "exec() failed.");
}

// 親プロセス
static void parent (pid_t pid_child)
{
    printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_child);
    exit(EXIT_SUCCESS);
}