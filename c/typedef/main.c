#include <stdio.h>

enum tag_week {
    SUN,
    MON,
    TUE,
    WED,
    THR,
    FRI,
    SAT,
};

// typedef
// 構造体・共用体・列挙型などのデータ型にエイリアスを設定する
// typedef データ型 データ エイリアス名 という記法
typedef enum tag_week week_t;

// また, 複数の型のエイリアスを同時に宣言にすることもできる
typedef struct {
    // somethig ...
} foo, *bar;

int main(int argc, char *argv[]) {
    return 0;
}