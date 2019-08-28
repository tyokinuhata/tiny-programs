#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MSG_MAX_LEN 255

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 2) serv_port = atoi(argv[1]);

    // 待ち受け用のソケットを作成
    int serv_sock;
    if ((serv_sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(serv_port);

    // バインド
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) < 0) exit(EXIT_FAILURE);

    // 受信
    struct sockaddr_in clnt_addr;
    unsigned int clnt_addr_len = sizeof(struct sockaddr_in);
    int recv_msg_len;
    char recv_msg[MSG_MAX_LEN];
    for (;;) {
        if ((recv_msg_len = recvfrom(serv_sock, recv_msg, MSG_MAX_LEN, 0, (struct sockaddr *)&clnt_addr, &clnt_addr_len)) < 0) exit(EXIT_FAILURE);

        printf("Handling client: %s\n", inet_ntoa(clnt_addr.sin_addr));

        if (sendto(serv_sock, recv_msg, recv_msg_len, 0, (struct sockaddr *)&clnt_addr, sizeof(struct sockaddr_in)) != recv_msg_len) exit(EXIT_FAILURE);
    }
}