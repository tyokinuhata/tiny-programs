// プラグマ演算子
// マクロ内で処理系定義の機能を使用するための機能
// #pragmaプリプロセッサを演算子化したもの
#include <stdio.h>

#define PRAGMA_STR(n) _Pragma(#n)
#define PRAGMA(n) PRAGMA_STR(pack(n))

int main(void) {
    PRAGMA(1);
    return 0;
}