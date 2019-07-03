#include <stdio.h>

#define FILE_NAME "sample.txt"

int main(int argc, char *argv[]) {
    FILE *fa;

    // fopen関数
    // ファイルを開く
    // fopen(ファイルパス, モード)
    // 戻り値はFILE型へのポインタ
    // モードにはr, r+, w, w+, a, a+ などがある
    fa = fopen(FILE_NAME, "a");

    // ファイルのオープンに失敗
    if (fa == NULL) return -1;

    // fprintf関数
    // ストリームへ指定された書式に変換して出力
    // fprintf(ストリーム, 文字列)
    // 単にストリームへ書き込む関数としてfwrite関数もある
    for (int i = 0; i < 10; i++) fprintf(fa, "hello, world!\n");

    // fclose関数
    // ストリームを閉じる
    // fclose(ストリーム)
    fclose(fa);



    FILE *fr;
    fr = fopen(FILE_NAME, "r");

    // fgets関数
    // ストリームから文字列の入力
    // fgets(出力先, サイズ, ストリーム)
    // ファイルを読み込む関数としてfread関数もある
    char s[16];
    while (fgets(s, 16, fr) != NULL) {
        printf("%s", s);
    }

    fclose(fr);

    // 他にも, サイズの大きいファイルを読む場合に使える関数として,

    // ftell関数
    // 現在ストリームのどの場所にいるか
    // ftell(ストリーム)
    // 戻り値はlong

    // fseek関数
    // ストリームの指定した場所への移動
    // fseek(ストリーム, 場所, どこから)
    // 戻り値はint
    // まだ, 第三引数には, SEEK_SET(ファイルの先頭から), SEEK_CUR(現在の場所からの相対位置), SEEK_END(ファイルの末尾から)

    // なども存在する

    return 0;
}