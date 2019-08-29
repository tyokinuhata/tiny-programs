// BPF(Berkeley Packet Filter)
// BSD系(macOS等)でレイヤ層を扱うための仕組み
// ソケットAPIを介さない作りになっている
// sudo ./a.out <if_name>

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <string.h>
// open関数, O_RDWRマクロを使うために必要
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <net/if.h>
// BIOCSEIFマクロを使うために必要
#include <net/bpf.h>

#define BPF_DEVICE_NUM 4

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc != 2) {
        fprintf(stderr, "usage: %s if_name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // fd ... file descriptor
    int fd = -1;
    char path[16];
    // /dev/bpfX 形式のデバイスファイルが複数用意されている
    // 複数用意されているのは複数のプロセスで同時にBPFを利用できるようにするため
    // BPFのデバイスファイルは一度オープンするとクローズするまで他のプロセスからはオープンできない
    // そのため, BPFを使用する際は, デバイスファイルのうち使用されていないものをオープンする必要がある
    // そのための探索処理
    for (int i = 0; i < BPF_DEVICE_NUM; i++) {
        // snprintf関数
        // int snprintf(char *restrict s, size_t n, const char *restrict format, ...)
        // formatが示す書式文字列に従ってsが指す文字配列へ書き込みを行う
        snprintf(path, sizeof(path), "/dev/bpf%d", i);
        // open関数
        // int open(const char *pathname, int flags, mode_t mode)
        // pathnameに対応するファイルディスクリプタが作成され, そのファイルディスクリプタが返される
        // O_RDWR ... 読み書き両用でオープンする
        // modeはファイル作成時のモード(0はおそらくデフォルト)
        fd = open(path, O_RDWR, 0);
        if (fd != -1) break;
    }
    if (fd == -1) err(EXIT_FAILURE, "open");

    char *if_name = argv[1];
    struct ifreq if_req;
    // IFNAMSIZ ... パケットソケットで使用したIF_NAMESIZE的なものだと思う
    //              どちらも16をdefineしたもの
    //              前者はif_var.h, 後者はif.hで定義されていた
    strncpy(if_req.ifr_name, if_name, IFNAMSIZ - 1);
    // BIOCSETIF ... インタフェースの設定
    if (ioctl(fd, BIOCSETIF, &if_req) < 0) {
        perror("ioctl [BIOCSETIF]");
        close(fd);
        exit(EXIT_FAILURE);
    }
    unsigned int size;
    // BIOCGBLEN ... bpfファイル上で読み込むために必要なバッファ長を取得する
    if (ioctl(fd, BIOCGBLEN, &size) < 0) {
        perror("ioctl [BIOCGBLEN]");
        close(fd);
        exit(EXIT_FAILURE);
    }
    char *buf = malloc(size);
    if (!buf) {
        fprintf(stderr, "malloc: failure\n");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // BIOCPROMISC ... 強制的にプロミスキャスモードに変更する(全てのインタフェースのパケットを取得できるようにする)
    if (ioctl(fd, BIOCPROMISC, NULL) , 0) {
        perror("ioctl [BIOCPROMISC]");
        free(buf);
        close(fd);
        exit(EXIT_FAILURE);
    }
    int enable = 1;
    // BIOCIMMEDIATE ... 直接モードを有効 or 無効にする
    //                   有効: read関数はパケットの受信でただちに返る
    //                   無効: read関数はバッファがいっぱいになるか, タイムアウトが起きるまでブロックする
    if (ioctl(fd, BIOCIMMEDIATE, &enable) < 0) {
        perror("ioctl [BIOCIMMEDIATE]");
        free(buf);
        close(fd);
        exit(EXIT_FAILURE);
    }
    // BIOCSHDRCMPLT ... ヘッダ完全フラグを有効 or 無効にする
    if (ioctl(fd, BIOCSHDRCMPLT, &enable) < 0) {
        perror("ioctl [BIOCSHDRCMPLT]");
        free(buf);
        close(fd);
        exit(EXIT_FAILURE);
    }
    ssize_t recv_size;
    for (;;) {
        // read関数
        // ssize_t read(int fd, void *buf, size_t count)
        // 指定したファイルディスクリプタから内容を最大countバイトをbufへ読み込む
        recv_size = read(fd, buf, size);
        if (recv < 0) {
            if (errno == EINTR) continue;
            perror("read");
            free(buf);
            close(fd);
            exit(EXIT_FAILURE);
        }
        unsigned int offset = 0;
        struct bpf_hdr *handler = (struct bpf_hdr *)buf;
        while ((uintptr_t)handler < (uintptr_t)buf + recv_size) {
            printf("read [%d]: %d bytes via %s\n", offset++, handler->bh_caplen, if_name);
            // BPF_WORDALIGNマクロ関数
            // ワード境界を考慮したパディング分のサイズを付加してくれる
            handler = (struct bpf_hdr *)((uintptr_t)handler + BPF_WORDALIGN(handler->bh_hdrlen + handler->bh_caplen));
        }
    }
    free(buf);
    close(fd);
    exit(EXIT_SUCCESS);
}