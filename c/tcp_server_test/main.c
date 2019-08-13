#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "tcp_server.h"

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 2) serv_port = atoi(argv[1]);

    // 待ち受け用のソケットの作成
    int serv_sock;
    if ((serv_sock = setup_tcp_serv_sock(serv_port)) < 0) exit(EXIT_FAILURE);

    struct sockaddr_in clnt_addr;
    unsigned int clnt_addr_len = sizeof(struct sockaddr_in);
    int clnt_sock;
    for (;;) {
        // accept
        if((clnt_sock = ac_tcp_serv_con(serv_sock)) < 0) exit(EXIT_FAILURE);

        echo_back(clnt_sock);

        close(clnt_sock);
    }
}