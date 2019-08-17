// ブロードキャスト(送信側)
// ブロードキャスト ... 送信側でパケットをコピーするのではなく, 適切なタイミングでネットワークにコピーしてもらう方式. 以下の２種類がある
// ローカルブロードキャストアドレス ... 送信したホストと同じネットワークにある全てのホストに送信. 255.255.255.255
// ダイレクトブロードキャストアドレス ... 特定のネットワークにある全てのホストに送信
// UDPはブロードキャストを使用できるが, TCPは使用できない

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// ./a.out <ip_address> <message> <port(optional)>
int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc < 3 || argc > 4) exit(EXIT_FAILURE);

    // ブロードキャストのIPアドレスと送信するメッセージの設定
    char *broadcast_ip = argv[1];
    char *send_msg = argv[2];

    // サーバのポート番号の設定
    unsigned short port = 7;
    if (argc == 4) port = atoi(argv[3]);

    // ソケットの作成
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) exit(EXIT_FAILURE);

    // ブロードキャスト用の設定
    int broadcast_permission = 1;
    // setsockopt関数
    // ソケットのオプションを設定する
    // int setsockopt(int socket, int level, int optName, const void *optVal, unsigned int optLen)
    // level: SOL_SOCKET ... プロトコルに依存せずにソケットレイヤ自体で処理する場合
    //        IPPROTO_TCP ... トランスポート層固有のオプションの場合
    //        IPPROTO_IP ... ネットワーク層固有のオプションの場合
    // ソケットのオプションを取得する関数にgetsockopt関数も存在する
    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (void *)&broadcast_permission, sizeof(int)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(broadcast_ip);
    addr.sin_port = port;

    unsigned int send_msg_len = strlen(send_msg);
    for (;;) {
        puts("Sending now ...");
        if (sendto(sock, send_msg, send_msg_len, 0, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != send_msg_len) exit(EXIT_FAILURE);
        sleep(3);
    }
}