#define ENV 1

// #if ENV == 1 と同義
#ifdef ENV
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("hello, world!\n");
    return 0;
}
#else
#endif

// #if ENV == 0 と同義
#ifndef ENV
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("hello, world!\n");
    return 0;
}
#else
#endif