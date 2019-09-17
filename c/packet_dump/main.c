#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netpacket/packet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUF_SIZE 65535

void dump_ethernet(u_char *);
void dump_ip(u_char *);
void dump_tcp(u_char *);
char *mac_ntoa(u_char *);

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

// イーサネットフレームのダンプ
void dump_ethernet (u_char *buf)
{
    struct ether_header *eth_header = (struct ether_header *)buf;

    puts("----- Ethernet Header -----");
    printf("Dest Mac: %s\n", mac_ntoa(eth_header->ether_dhost));
    printf("Source Mac: %s\n", mac_ntoa(eth_header->ether_shost));

    printf("Type: ");
    switch (ntohs(eth_header->ether_type)) {
        case ETH_P_IP:
            puts("IP");
            u_char *ip_buf = buf;
            ip_buf += sizeof(struct ether_header);
            dump_ip(ip_buf);
            break;
        case ETH_P_IPV6:
            puts("IPv6");
            puts("--------------------\n");
            break;
        case ETH_P_ARP:
            puts("ARP");
            puts("--------------------\n");
            break;
        default:
            puts("UNKNOWN");
            puts("--------------------\n");
            break;
    }
}

// IPデータグラムのダンプ
void dump_ip (u_char *buf)
{
    struct iphdr *ip_header = (struct iphdr *)buf;
    puts("----- IP Header -----");
    printf("Version: %u\n", ip_header->version);
    printf("IHL: %u\n", ip_header->ihl);
    printf("Type of Service: %u\n", ip_header->tos);
    printf("Total Length: %u\n", ntohs(ip_header->tot_len));
    printf("Identification: %u\n", ntohs(ip_header->id));
    printf("Time to Live: %u\n", ip_header->ttl);
    printf("Protocol: %u\n", ip_header->protocol);

    // 上位層のプロトコルがTCP(6)の場合
    if (ip_header->protocol == 6) {
        u_char *tcp_buf = buf;
        tcp_buf += ip_header->ihl * 4;
        dump_tcp(tcp_buf);
    }
    else puts("--------------------\n");
}

// TCPセグメントのダンプ
void dump_tcp (u_char *buf)
{
    struct tcphdr *tcp_header = (struct tcphdr *)buf;
    puts("----- TCP Header -----");
    printf("Source Port: %u\n", ntohs(tcp_header->source));
    printf("Destination Port: %u\n", ntohs(tcp_header->dest));
    puts("--------------------\n");
}

// MACアドレスを文字列に変換する
char *mac_ntoa (u_char *network_mac)
{
    #define MAX_MAC_LEN 50
    static char str_mac[MAX_MAC_LEN];

    snprintf(str_mac, MAX_MAC_LEN, "%02x:%02x:%02x:%02x:%02x:%02x", network_mac[0], network_mac[1], network_mac[2], network_mac[3], network_mac[4], network_mac[5]);

    return str_mac;
}