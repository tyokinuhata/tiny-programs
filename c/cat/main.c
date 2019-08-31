// シンプルなcatコマンドの実装
// cat ... conCATenate(連結する)の略
// なぜconcatenateか => $ cat a b c > out のようにすると複数のファイルを連結できるため
// ./a.out <path>

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
    // ファイルディスクリプタの生成
    // int open(const char *path, int flags, mode_t mode)
    // flags
    // O_RDONLY ... 読込専用
    // O_WRONLY ... 書込専用
    // O_RDWR ... 読書両用
    // mode
    // O_CREAT ... ファイルが存在しなければ新しいファイルを生成する
    // O_EXCL ... O_CREATと共に指定できる. すでにファイルが存在した場合, エラーになる
    // O_TRUNC ... O_CREATと共に指定できる. ファイルが存在する場合はファイルの長さを0にする
    // O_APPEND ... write()が常にファイル末尾に書き込むようになる
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    u_char buf[BUF_SIZE];
    ssize_t r_size;
    for (;;) {
        // ファイルから読み込み
        // ssize_t read(int fd, void *buf, size_t bufsize)
        r_size = read(fd, buf, sizeof(buf));
        // エラー処理
        if (r_size < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        // 終端処理
        if (r_size == 0) break;

        // 標準出力に書き込み
        // ssize_t write(int fd, const void *buf, size_t bufsize)
        if (write(STDOUT_FILENO, buf, r_size) < 0) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    // ファイルを閉じる
    // int close(int fd)
    if (close(fd) < 0) {
        perror("close");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}