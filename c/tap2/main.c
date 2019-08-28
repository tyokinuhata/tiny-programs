// TUNデバイスのサンプル(インタフェース名を指定可能)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/if_tun.h>

#define CLONE_DEVICE "/dev/net/tun"

int main (int argc, char **argv)
{
    // ファイルディスクリプタの作成
    int fd = open(CLONE_DEVICE, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // インタフェース名の設定
    struct ifreq if_req;
    memset(&if_req, 0, sizeof(if_req));
    switch (argc) {
        case 1:
            break;
        case 2:
            strncpy(if_req.ifr_name, argv[1], sizeof(if_req.ifr_name) - 1);
            break;
        default:
            fprintf(stderr, "usage: %s <tap_device_name>\n", argv[0]);
            close(fd);
            exit(EXIT_FAILURE);
    }

    // インタフェースの設定
    if_req.ifr_flags = IFF_TAP | IFF_NO_PI;
    if (ioctl(fd, TUNSETIFF, &if_req) < 0) {
        perror("ioctl [TUNSETIFF]");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 受信
    char *if_name = if_req.ifr_name;
    ssize_t recv_size;
    char buf[2048];
    printf("if_name: %s\n", if_name);
    for (;;) {
        recv_size = read(fd, buf, sizeof(buf));
        if (recv_size == -1) {
            if (errno == EINTR) continue;
            perror("read");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("recv: %zd via %s\n", recv_size, if_name);
    }
    close(fd);
    exit(EXIT_SUCCESS);
}