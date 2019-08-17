#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int resolve_service(const char *, const char *);

// ./a.out echo tcp
int main (int argc, char **argv)
{
    if (argc < 3 || argc > 3) exit(EXIT_FAILURE);

    // ホスト名(echo等)
    char *service = argv[1];
    // プロトコル(TCP・UDP等)
    char *protocol = argv[2];

    int port;
    if ((port = resolve_service(service, protocol)) < 0) exit(EXIT_FAILURE);

    printf("Port number: %d\n", port);
}

// サービスの検索
int resolve_service (const char *service, const char *protocol)
{
    struct servent *serv;
    // getservbyname関数
    // アプリケーションプロトコルに関する情報をサービス名とプロトコル(TCP/UDP)から取得する関数
    // ローカルにあるDBか/etc/servicesの情報から取得する(実装依存)
    // サービスの検索にDNSのようなプロトコルは用意されていない
    // struct servent *getservbyname(const char *serviceName, const char *protocol)
    // 戻り値はservent構造体
    // getservbyname関数と逆の作用をする関数としてgetservbyport関数も用意されている
    if ((serv = getservbyname(service, protocol)) == NULL) return -1;
    else return serv->s_port;
}