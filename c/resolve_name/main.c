#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

int resolve_name(char *, struct in_addr *);

// ./a.out google.com
int main (int argc, char **argv)
{
    if (argc < 2 || argc > 2) exit(EXIT_FAILURE);

    // ホスト名
    char *host_name = argv[1];

    struct in_addr addr;
    if (resolve_name(host_name, &addr) < 0) exit(EXIT_FAILURE);

    printf("%s\n", inet_ntoa(addr));
}

// 名前解決
int resolve_name (char *host_name, struct in_addr *addr)
{
    struct hostent *host;
    // gethostbyname関数
    // ホスト名を引数として取り, IPアドレス等のホスト情報を返す関数
    // struct hostent *gethostbyname(const char *hostName)
    // 戻り値はhostent構造体
    if ((host = gethostbyname(host_name)) == NULL) return -1;

    addr->s_addr = *((unsigned long *)host->h_addr_list[0]);

    return 0;
}