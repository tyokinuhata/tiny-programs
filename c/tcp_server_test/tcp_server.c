#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// 最大接続数
#define MAX_PENDING 5
// バッファのサイズ
#define RECV_BUF_SIZE 32

// TCPサーバのソケットをセットアップ
int setup_tcp_serv_sock(unsigned short port)
{
    // 待ち受け用のソケットの作成
    int sock;
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) return -1;

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(struct sockaddr_in));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    // バインド
    if (bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) < 0) return -1;

    // リッスン
    if (listen(sock, MAX_PENDING) < 0) return -1;

    return sock;
}

// accept
int ac_tcp_serv_con(int serv_sock)
{
    struct sockaddr_in clnt_addr;
    unsigned int clnt_addr_len = sizeof(struct sockaddr_in);
    int clnt_sock;

    if ((clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_len)) < 0) return -1;

    printf("Handling client: %s\n", inet_ntoa(clnt_addr.sin_addr));

    return clnt_sock;
}

// エコーバック
int echo_back (int clnt_sock)
{
    int recv_msg_len;
    char recv_buf[RECV_BUF_SIZE];
    if ((recv_msg_len = recv(clnt_sock, recv_buf, RECV_BUF_SIZE, 0)) < 0) return -1;

    while (recv_msg_len > 0) {
        if (send(clnt_sock, recv_buf, recv_msg_len, 0) != recv_msg_len) return -1;
        if ((recv_msg_len = recv(clnt_sock, recv_buf, RECV_BUF_SIZE, 0)) < 0) return -1;
    }

    return 0;
}