#include <stdio.h>

// define命令
// プリプロセス時にソースコード中のHOGEが100に置換される
// #define 置換前 置換後
#define HOGE 4;

int main(int argc, char *argv[]) {
    int hoge = HOGE;

    printf("%d\n", 330 + hoge);

    return 0;
}