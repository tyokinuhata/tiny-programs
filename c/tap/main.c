// TUN/TAP
// 仮想ネットワークデバイス(ハードウェアではなくソフトウェアで実現されているということ)
// TAP ... Terminal Access Point
//         リンク層をシミュレート・操作できる
// TUN ... TUNnel
//         ネットワーク層をシミュレート・操作できる
// TUNデバイスのサンプル(インタフェース名は自動生成)
// sudo ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if_tun.h>

#define CLONE_DEVICE "/dev/net/tun"

int main ()
{
    // ファイルディスクリプタの作成
    int fd = open(CLONE_DEVICE, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // インタフェースの設定
    struct ifreq if_req;
    memset(&if_req, 0, sizeof(if_req));
    // IFF_TAP ... TAPデバイス
    // IFF_NO_PI ... パケット情報を提供しない
    if_req.ifr_flags = IFF_TAP | IFF_NO_PI;
    // TAPデバイスにインタフェースの設定を適用
    if (ioctl(fd, TUNSETIFF, &if_req) < 0) {
        perror("ioctl [TUNSETIFF]");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 受信
    char *if_name = if_req.ifr_name;
    printf("if_name: %s\n", if_name);
    ssize_t recv_size;
    char buf[2046];
    for (;;) {
        recv_size = read(fd, buf, sizeof(buf));
        if (recv_size < 0) {
            if (errno == EINTR) continue;
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("read: %zd via %s\n", recv_size, if_name);
    }
}