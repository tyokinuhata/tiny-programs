#include <stdio.h>

// 列挙型
// 列挙した数値に名前を付ける型
// 0から順に割り振られるが, SUN = 0 のように自分で番号を割り振ることもできる
enum tag_week {
    SUN,
    MON,
    TUE,
    WED,
    THR,
    FRI,
    SAT,
};

int main(int argc, char *argv[]) {
    enum tag_week week;

    week = SAT;
    printf("%d\n", week);

    // int型と互換性があるため代入できる
    week = 3;
    printf("%d\n", week);

    // 列挙子はグローバルスコープであるため衝突に注意する
    int day = SUN;
    // 条件式にも使用できる
    if (day == SUN) printf("today is sun.\n");

    return 0;
}