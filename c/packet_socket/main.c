// パケットソケット
// ソケットAPIの枠組みの中でリンク層へアクセスする仕組み
// このサンプルコードでは全てのネットワークインタフェースから受信する
// 実行にはsudoが必要
// sudo ./a.out

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <err.h>
#include <unistd.h>
#include <sys/socket.h>
// ssize_t型を使うために必要
#include <sys/types.h>
#include <arpa/inet.h>
// if_indextoname関数を使うために必要
#include <net/if.h>
// sockaddr_ll構造体を使うために必要
#include <netpacket/packet.h>
// ETH_P_ALLを使うために必要
#include <net/ethernet.h>

int main ()
{
    // PF_PACKET ... リンク層やネットワーク層の生データを扱えるようにするプロトコルファミリー
    // SOCK_RAW ... リンク層のデータを扱えるようにする
    // SOCK_DGRAM ... ネットワーク層のデータを扱えるようにする
    // ETH_P_ALL ... 全てのプロトコルが受信される
    int sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) err(EXIT_FAILURE, "socket");

    // sockaddr_ll構造体
    // unsigned short sll_family ... AF_PACKET
    // unsigned short sll_protocol ... 物理層のプロトコル
    // int sll_ifindex ... インタフェース番号
    // unsigned short sll_hatype ... ARP ハードウェア種別
    // unsigned char sll_pkttype ... パケット種別
    // unsigned char sll_halen ... アドレスの長さ
    // unsigned char sll_addr[8] ... 物理層のアドレス
    struct sockaddr_ll addr;
    // socklen_t型
    // unsigned int型のエイリアス
    socklen_t addr_len;
    // ssize_t型
    // 自分の環境では符号付きlong型のエイリアスだった(size_t型は符号無し)
    ssize_t recv_size;
    char buf[2048];
    // IF_NAMESIZE ... インタフェース名のサイズ(自分の環境では16だった)
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
        // if_indextoname関数
        // char *if_indextoname(unsigned int ifindex, char *ifname)
        // インタフェースのインデックスがifindexに対応するネットワークインタフェース名をifnameにセットする
        // 戻り値は, 成功時はインデックスを返す. エラーの場合は0を返し, 適切なerrnoをセットする
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