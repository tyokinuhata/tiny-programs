#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
// ioctl関数を使うために必要
#include <sys/ioctl.h>
#include <arpa/inet.h>
// ifreq構造体を使うために必要
#include <net/if.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>

int main (int argc, char **argv)
{
    int sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) err(EXIT_FAILURE, "socket");

    // ifreq構造体
    // ioctl関数に渡してネットワークデバイスの設定や情報の取得を行うための構造体
    struct ifreq if_req;
    struct sockaddr_ll addr;
    switch (argc) {
        case 1:
            break;
        case 2:
            // strncpy関数
            // s2の先頭からn文字をs1にコピーする
            // char *strncpy(char *s1, const char *s2, size_t n)
            strncpy(if_req.ifr_name, argv[1], sizeof(if_req.ifr_name) - 1);
            // ioctl関数
            // int ioctl(int fd, unsigned long request, ...)
            // ネットワークデバイスの設定や情報の取得を行う
            // SIOCGIFINDEX ... ネットワークインタフェースのインデックスを取得し, ifreqのifr_ifindexフィールドに設定する
            if (ioctl(sock, SIOCGIFINDEX, &if_req) < 0) {
                perror("ioctl [SIOCGIFINDEX]");
                close(sock);
                exit(EXIT_FAILURE);
            }
            memset(&addr, 0, sizeof(addr));
            addr.sll_family = AF_PACKET;
            addr.sll_protocol = htons(ETH_P_ALL);
            addr.sll_ifindex = if_req.ifr_ifindex;
            if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
                perror("bind");
                close(sock);
                exit(EXIT_FAILURE);
            }
            break;
        default:
            fprintf(stderr, "usage: %s [if_name]\n", argv[0]);
            close(sock);
            exit(EXIT_FAILURE);

        socklen_t addr_len;
        ssize_t recv_size;
        char buf[2048];
        char if_name[IF_NAMESIZE];
        for (;;) {
            addr_len = sizeof(addr);
            recv_size = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addr_len);
            if (recv_size < 0) {
                if (errno == EINTR) continue;
                perror("recvfrom");
                close(sock);
                exit(EXIT_FAILURE);
            }
            if (!if_indextoname(addr.sll_ifindex, if_name)) {
                perror("if_indextoname");
                close(sock);
                exit(EXIT_FAILURE);
            }
            printf("recvfrom: %zd bytes via %s\n", recv_size, if_name);
        }
        close(sock);
        exit(EXIT_SUCCESS);
    }
}