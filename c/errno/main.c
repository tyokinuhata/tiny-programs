// perror関数, fprintf関数を使うために必要
#include <stdio.h>
#include <stdlib.h>
// 直近に発生したエラー番号をerrnoという整数型のグローバル変数に格納している
// 有効なエラー番号はいずれも0以外の値を持つ
// また, 各エラー番号をマクロで定義している
#include <errno.h>
// err関数を使うために必要
#include <err.h>

#include <sys/socket.h>

int main()
{
    // socket関数に変な値を設定する
    int sock = socket(3000, 4000, 5000);
    if (sock < 0) {
        // エラー番号の表示
        printf("%d\n", errno);

        // fprintf関数
        // int fprintf(FILE *restrict stream, const char *restrict fmt, ...)
        // fprintf(stderr, "%s", val) のように使うことも可能
        // "Error message"と出力される
        // fprintf(stderr, "Error message\n");
        // exit(EXIT_FAILURE);

        // perror関数
        // void perror(const char *s)
        // "socket: Address family not supported by protocol family"と出力される
        // perror("socket");
        // exit(EXIT_FAILURE);

        // err関数
        // void err(int eval, const char *fmt, ...)
        // err関数はstrerror関数から受け取ったerrnoに対応するエラーメッセージを元に出力する
        // "a.out: socket: Address family not supported by protocol family"と出力される
        // err(EXIT_FAILURE, "%s", val) のように使うことも可能
        // err(EXIT_FAILURE, "socket");
    }
    exit(EXIT_SUCCESS);
}