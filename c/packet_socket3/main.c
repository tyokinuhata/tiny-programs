// パケットソケット
// インタフェース名の指定必須
// sudo ./a.out <if_name>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc != 2) {
        fprintf(stderr, "usage: %s if_name\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // ソケットディスクリプタの生成
    int sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) err(EXIT_FAILURE, "socket");

    // インタフェースの設定
    char *if_name = argv[1];
    struct ifreq if_req;
    strncpy(if_req.ifr_name, if_name, sizeof(if_req.ifr_name) - 1);
    if (ioctl(sock, SIOCGIFINDEX, &if_req) < 0) {
        perror("ioctl [SIOCGIFINDEX]");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // アドレスの設定
    struct sockaddr_ll addr;
    memset(&addr, 0, sizeof(addr));
    addr.sll_family = AF_PACKET;
    addr.sll_protocol = htons(ETH_P_ALL);
    addr.sll_ifindex = if_req.ifr_ifindex;
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sock);
        exit(EXIT_FAILURE);
    }

    // 受信
    ssize_t recv_size;
    char buf[2048];
    for (;;) {
        // インタフェースが必ず指定されているため, recv関数を使用できる
        recv_size = recv(sock, buf, sizeof(buf), 0);
        if (recv_size < 0) {
            if (errno == EINTR) continue;
            perror("recv");
            close(sock);
            exit(EXIT_FAILURE);
        }
        printf("recv: %zd bytes via %s\n", recv_size, if_name);
    }
    close(sock);
    exit(EXIT_SUCCESS);
}