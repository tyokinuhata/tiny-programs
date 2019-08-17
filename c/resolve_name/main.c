// ホスト名 -> IPアドレス の名前解決

#include <stdio.h>
#include <stdlib.h>
// hostent構造体, gethostbyname関数を使うために必要
#include <netdb.h>
#include <arpa/inet.h>

struct in_addr *resolve_name(const char *);

// ./a.out google.com
int main (int argc, char **argv)
{
    if (argc < 2 || argc > 2) exit(EXIT_FAILURE);

    // ホスト名
    char *host_name = argv[1];

    struct in_addr *addr;
    if ((addr = resolve_name(host_name)) == NULL) exit(EXIT_FAILURE);

    printf("IP Address: %s\n", inet_ntoa(*addr));
}

// 名前解決
struct in_addr *resolve_name (const char *host_name)
{
    struct hostent *host;
    // gethostbyname関数
    // ホスト名を引数として取り, IPアドレス等のホスト情報を返す関数
    // DNSかローカルにあるDBから情報は取得する(実装依存)
    // struct hostent *gethostbyname(const char *hostName)
    // 戻り値はhostent構造体
    // gethostbyname関数と逆の作用をする関数としてgethostbyaddr関数も用意されている
    if ((host = gethostbyname(host_name)) == NULL) return NULL;

    static struct in_addr addr;
    addr.s_addr = *((unsigned long *)host->h_addr_list[0]);

    return &addr;
}