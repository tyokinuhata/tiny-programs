#include <stdio.h>
#include <time.h>

int main (int argc, char *argv[]) {
    time_t now = time(NULL);

    // ctime関数
    // 日付をカレンダー形式で表示する
    printf("%s", ctime(&now));

    return 0;
}