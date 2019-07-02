#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // メモリ領域を2GB確保
    char *p = malloc(2147483647);

    if (p == NULL) return -1;

    getchar();

    // コピーオンライト
    // mallocやcallocを実行しただけではメモリが確保されないことがある
    // メモリを確保したことにしておいて, 実際にプログラムからの書き込みが発生したときにメモリを確保する仕組み
    for (int i = 0; i < 2147483647; i++) {
        // 確保したメモリに一要素ずつ書き込む
        p[i] = 1;
    }

    free(p);

    return 0;
}