// TUN/TAP
// 仮想ネットワークデバイス(ハードウェアではなくソフトウェアで実現されているということ)
// TAP ... Terminal Access Point
//         リンク層をシミュレート・操作できる
// TUN ... TUNnel
//         ネットワーク層をシミュレート・操作できる

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define CLONE_DEVICE "/dev/net/tun"

int main ()
{
    int fd = open(CLONE_DEVICE, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct ifreq if_req;
    memset(&if_req, 0, sizeof(if_req));
    if_req.ifr_flags = IFF_TAP | IFF_NO_PI;
    if (ioctl(fd, TUNSETIFF, &if_req) < 0) {
        perror("ioctl [TUNSETIFF]");
        close(fd);
        exit(EXIT_FAILURE);
    }

    char *if_name = if_req.ifr_name;
    fprintf(stderr, "if_name: %s\n", if_name);
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