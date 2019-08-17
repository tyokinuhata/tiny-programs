// マルチキャスト
// 特定の複数のノードに対して同時にパケットを送信する
// マルチキャストには専用のアドレス空間が用意されており, 224.0.0.0〜239.255.255.255

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// ./a.out <ip_address> <message> <port(optional)> <ttl(optional)>
int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc < 3 || argc > 5) exit(EXIT_FAILURE);

    // マルチキャストのIPアドレスと送信するメッセージの設定
    char *multicast_ip = argv[1];
    char *send_msg = argv[2];

    // サーバのポート番号の設定
    unsigned short port = 7;
    if (argc == 4) port = atoi(argv[3]);

    // TTLの設定
    unsigned char ttl = 1;
    if (argc == 5) ttl = atoi(argv[4]);

    // ソケットの作成
    int sock;
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) exit(EXIT_FAILURE);

    // マルチキャスト用の設定
    // ブロードキャストとは違い, マルチキャストを設定で有効化する必要は無い
    // TTL(Time To Live)はルータを通過する毎に1ずつデクリメントされる. 0になるとそのパケットは破棄される
    // このTTLの仕組みを上手く利用することでホップ数を制限することができる
    if (setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&ttl, sizeof(unsigned char)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(multicast_ip);
    addr.sin_port = htons(port);

    unsigned int send_msg_len = strlen(send_msg);
    for (;;) {
        puts("Sending now ...");
        if (sendto(sock, send_msg, send_msg_len, 0, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != send_msg_len) exit(EXIT_FAILURE);
        sleep(3);
    }
}