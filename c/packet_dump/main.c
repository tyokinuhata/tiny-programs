#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
// #include <netpacket/packet.h>

#define BUF_SIZE 65535

void dump_ethernet(u_char *);

int main ()
{
    u_char buf[BUF_SIZE];

    int sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_ll addr;
    socklen_t addr_len;
    ssize_t recv_size;
    for (;;) {
        addr_len = sizeof(addr);
        recv_size = recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addr_len);
        if (recv_size < 0) {
            perror("recvfrom");
            close(sock);
            exit(EXIT_FAILURE);
        }
        dump_ethernet(buf);
    }
}

void dump_ethernet (u_char *buf)
{
    struct ether_header *eth_header = (struct ether_header *)buf;

    printf("type: ");
    switch (ntohs(eth_header->ether_type)) {
        case ETH_P_IP:
            printf("ip\n");
            break;
        case ETH_P_ARP:
            printf("arp\n");
            break;
        default:
            printf("unknown\n");
            break;
    }
}