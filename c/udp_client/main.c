// UDPクライアント
// クライアントとサーバでTCPで通信を行うサンプル
// アプリケーション層のプロトコルにはEcho Protocolを使用する

// UDPサーバ
// サーバにはNetCatを使用して検証した
// sudo netcat -u -l 127.0.0.1 -p 7 -e /bin/cat -vv
// -u ... UDPを使用する
// sudoを付けないとPermission deniedになる

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MSG_MAX_LEN 255

// ./a.out 127.0.0.1 'hello, world!'
// ./a.out 127.0.0.1 'hello, world!' 7
int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc < 3 || argc > 4) exit(EXIT_FAILURE);

    // サーバのIPアドレスと送信するメッセージの設定
    char *serv_ip = argv[1];
    char *send_msg = argv[2];

    // 送信するメッセージの長さの範囲チェック
    int send_msg_len;
    if ((send_msg_len = strlen(send_msg)) > MSG_MAX_LEN) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 4) serv_port = atoi(argv[3]);

    // ソケットの作成
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in send_addr;
    memset(&send_addr, 0, sizeof(struct sockaddr_in));
    send_addr.sin_family = AF_INET;
    send_addr.sin_addr.s_addr = inet_addr(serv_ip);
    send_addr.sin_port = htons(serv_port);

    // メッセージの送信
    // sendto関数
    // sendto(int socket, const void *msg, unsigned int msgLength, int flags, struct sockaddr *destAddr, unsigned int addrLen)
    // 戻り値はメッセージの長さ
    if (sendto(sock, send_msg, send_msg_len, 0, (struct sockaddr *)&send_addr, sizeof(struct sockaddr_in)) != send_msg_len) exit(EXIT_FAILURE);

    // メッセージの受信
    // recvfrom関数
    // recvfrom(int socket, void *msg, unsigned int msgLength, int flags, struct sockaddr *srcAddr, unsigned int *addrLen)
    // 戻り値はメッセージの長さ
    int recv_msg_len;
    char recv_msg[MSG_MAX_LEN + 1];
    struct sockaddr_in recv_addr;
    unsigned int recv_addr_len = sizeof(struct sockaddr_in);
    if ((recv_msg_len = recvfrom(sock, recv_msg, MSG_MAX_LEN, 0, (struct sockaddr *)&recv_addr, &recv_addr_len)) != send_msg_len) exit(EXIT_FAILURE);

    // 送信時のIPアドレスと受信時のIPアドレスが一致しているかのチェック
    if (send_addr.sin_addr.s_addr != recv_addr.sin_addr.s_addr) exit(EXIT_FAILURE);

    recv_msg[recv_msg_len] = '\0';
    printf("Received: %s\n", recv_msg);

    close(sock);
    exit(EXIT_SUCCESS);
}