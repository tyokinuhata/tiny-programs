// ブロードキャスト(受信側)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MSG_MAX_LEN 255

// ./a.out <port(optional)>
int main (int argc, char **argv)
{
    if (argc < 1 || argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short port = 7;
    if (argc == 4) port = atoi(argv[3]);

    // ソケットの作成
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    // バインド
    if (bind(sock, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) < 0) exit(EXIT_FAILURE);

    // メッセージの受信処理
    int recv_msg_len;
    char recv_msg[MSG_MAX_LEN + 1];
    if ((recv_msg_len = recvfrom(sock, recv_msg, MSG_MAX_LEN, 0, NULL, 0)) < 0) exit(EXIT_FAILURE);

    // メッセージの表示
    recv_msg[recv_msg_len] = '\0';
    printf("Received: %s\n", recv_msg);

    // 終了処理
    close(sock);
    exit(EXIT_SUCCESS);
}