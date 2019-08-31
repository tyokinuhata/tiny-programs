// シンプルなcatコマンドの実装
// cat ... conCATenate(連結する)の略
// なぜconcatenateか => $ cat a b c > out のようにすると複数のファイルを連結できるため
// 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUF_SIZE 2048

static void concat(const char *path);

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
    // ファイルのオープン(読込専用)
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    u_char buf[BUF_SIZE];
    ssize_t r_size;
    for (;;) {
        // ディスクリプタから読み込み
        r_size = read(fd, buf, sizeof(buf));
        // エラー処理
        if (r_size < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        // 終端処理
        if (r_size == 0) break;

        // 書き込み
        if (write(STDOUT_FILENO, buf, r_size) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    // 閉じる
    if (close(fd) < 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
}