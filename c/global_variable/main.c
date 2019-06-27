#include <stdio.h>

// 大域変数・グローバル変数
// プログラムのどこからでも読み書き可能
int global = 0;

void func1() {
    printf("%d\n", ++global);
}

void func2() {
    printf("%d\n", ++global);
}

void func3() {
    printf("%d\n", ++global);
}

int main (int argc, char *argv[]) {
    func1();
    func2();
    func3();

    return 0;
}