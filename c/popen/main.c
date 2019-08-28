#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 32768

int main ()
{
    // popen関数
    // プロセスをオープンする関数
    // 具体的にはパイプを生成し, フォークを行い, シェルを起動する
    // FILE *popen(const char *command, const char *type)
    // パイプは一方向のため, typeには読み込み(r)か書き込みの一方しか指定できない
    FILE *fp = popen("ls", "r");
    if (fp == NULL) exit(EXIT_FAILURE);

    char buf[BUF_SIZE];
    for (;;) {
        // fgets関数
        // char *fgets(char *restrict s, int n, FILE *restrict stream)
        // streamが指すストリームから一行分(正確には改行文字 or ファイルの終わりまで)を読み取り, sが指す配列に格納する
        fgets(buf, sizeof(buf), fp);
        // feof関数
        // int feof(FILE *stream)
        // streamが指すストリームがEOF(大抵の環境では-1)かどうかを判定する
        if (feof(fp)) break;
		printf("> %s", buf);
    }
    // pclose関数
    // int pclose(FILE *stream)
    // パイプに関連付けられたプロセスが終了するのを待ち, wait4関数によって返されたコマンドの終了状態を返す
    pclose(fp);
    exit(EXIT_SUCCESS);
}