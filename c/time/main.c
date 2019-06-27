#include <stdio.h>
// time関数やtime_t型を使うために必要
#include <time.h>

int main (int argc, char *argv[]) {

    // time関数
    // 現在時刻の取得(1970/1/1からの経過秒)
    time_t now = time(NULL);

    printf("%ld\n", now);

    return 0;
}