// タイムアウト
// UDPサーバからの応答が無い場合, 簡素な実装ではUDPクライアントがパケットの到着を延々と待ち続けることになる
// そこで, 一定時間応答が無かった場合にはタイムアウトとして処理する仕組みを導入する

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
// alarm関数を使うために必要
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MSG_MAX_LEN 255
// 再送までの秒数
#define TIMEOUT_SECS 2
// 最大試行回数
#define MAX_TRIES 5

// 送信回数のカウンタ
int tries = 0;

void catch_alarm(int);

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc < 3 || argc > 4) exit(EXIT_FAILURE);

    // サーバのIPアドレスと送信するメッセージの設定
    char *serv_ip = argv[1];
    char *send_msg = argv[2];

    // 送信するメッセージの長さのチェック
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

    // シグナルの動作を定義する構造体の作成
    struct sigaction handler;
    handler.sa_handler = catch_alarm;
    if (sigfillset(&handler.sa_mask) < 0) exit(EXIT_FAILURE);
    handler.sa_flags = 0;

    // シグナルSIGALRMに適用
    if (sigaction(SIGALRM, &handler, 0) < 0) exit(EXIT_FAILURE);

    // メッセージの送信
    if (sendto(sock, send_msg, send_msg_len, 0, (struct sockaddr *)&send_addr, sizeof(struct sockaddr_in)) != send_msg_len) exit(EXIT_FAILURE);

    int recv_msg_len;
    char recv_buf[MSG_MAX_LEN];
    struct sockaddr_in recv_addr;
    unsigned int recv_addr_len = sizeof(struct sockaddr_in);
    // alarm関数
    // unsigned int alarm(unsigned int secs)
    // タイマを開始し, secs秒経過すると期限切れとしてSIGALRMシグナルが送られる
    // 戻り値は過去にスケジュールされた任意のアラームの残り秒数 or 何もスケジュールされていなければ0が返される
    alarm(TIMEOUT_SECS);
    while ((recv_msg_len = recvfrom(sock, recv_buf, MSG_MAX_LEN, 0, (struct sockaddr *)&recv_addr, &recv_addr_len)) < 0) {
        // ２秒経過するとSIGALRMシグナルが送信され, ハンドラが起動する
        // ハンドラが処理を返すとブロックされていたrecvfrom関数はerrnoをEINTRに設定し, -1を返す
        if (errno == EINTR) {
            if (tries < MAX_TRIES) {
                printf("Time out, %d more tries ...\n", MAX_TRIES - tries);
                if (sendto(sock, send_msg, send_msg_len, 0, (struct sockaddr *)&send_addr, sizeof(struct sockaddr_in)) != send_msg_len) exit(EXIT_FAILURE);
                alarm(TIMEOUT_SECS);
            } else {
                exit(EXIT_FAILURE);
            }
        } else {
            exit(EXIT_FAILURE);
        }
    }

    alarm(0);

    // 受信データの表示
    recv_buf[recv_msg_len] = '\0';
    printf("Received: %s\n", recv_buf);

    // 終了
    close(sock);
    exit(EXIT_SUCCESS);
}

// シグナル処理関数
void catch_alarm(int ignored)
{
    tries += 1;
}