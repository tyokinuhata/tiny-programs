// シンプルなcatコマンドの実装
// stdio版
// stdioはopen, close, read, writeといったシステムコールをバイト単位で使用できるようにラップしている
// ./a.out <path>

#include <stdio.h>
#include <stdlib.h>

static void concat(const char *);

int main (int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "%s: file name is not given.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        concat(argv[i]);
    }
}

static void concat (const char *path)
{
    FILE *f;
    // ファイルのオープン
    // FILE *fopen(const char *path, const char *mode)
    // pathで示されたパスのファイルに繋がるストリームを作成し, それを管理するFILEへのポインタを返す
    // 失敗時にはNULLを返し, 原因を示す定数をerrnoにセットする
    // modeにはr, w, a, r+, w+, a+が指定できる
    f = fopen(path, "r");
    if (!f) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    int c;
    // int fgetc(FILE *stream)
    // 引数のファイルから1byte読み込んで返す
    // ファイルが終端の場合はEOF(大抵の場合は-1)を返す
    while ((c = fgetc(f)) != EOF) {
        // int putchar(int c)
        // 標準出力にcで指定された文字を書き込む
        if (putchar(c) < 0) {
            perror("putchar");
            exit(EXIT_FAILURE);
        }
    }
    // ファイルを閉じる
    // int fclose(FILE *stream)
    fclose(f);
    exit(EXIT_SUCCESS);
}