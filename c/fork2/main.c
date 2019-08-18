#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>

static void child();
static void parent(pid_t);

int main ()
{
    pid_t pid = fork();
    if (pid == -1)  err(EXIT_FAILURE, "fork() failed.");
    if (pid == 0)   child();
    else            parent(pid);
    err(EXIT_FAILURE, "shouldn't reach here.");
}

// 子プロセス
static void child()
{
    printf("I'm child! my pid is %d.\n", getpid());
    exit(EXIT_SUCCESS);
}

// 親プロセス
static void parent(pid_t pid_child)
{
    printf("I'm parent! my pid is %d and the pid of my child is %d.\n", getpid(), pid_child);
    exit(EXIT_SUCCESS);
}