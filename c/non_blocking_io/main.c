#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>
// fcntl関数を使用するのに必要
#include <fcntl.h>
// O_NONBLOCK, FASYNCを使うために必要
#include <sys/file.h>
// errnoを使うために必要
#include <errno.h>

#define MSG_MAX_LEN 255

void use_idle_time();
void sig_io_handler(int);

// sig_io_handler関数からも参照するため, グローバル変数として宣言する
int serv_sock;

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 2) serv_port = atoi(argv[1]);

    // 待ち受け用のソケットを作成
    if ((serv_sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(serv_port);

    // バインド
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) < 0) exit(EXIT_FAILURE);

    // シグナルの動作を定義する構造体の作成
    struct sigaction handler;
    handler.sa_handler = sig_io_handler;
    if (sigfillset(&handler.sa_mask) < 0) exit(EXIT_FAILURE);
    handler.sa_flags = 0;

    // SIGIOに適用
    if (sigaction(SIGIO, &handler, 0) < 0) exit(EXIT_FAILURE);

    // fcntl関数
    // fcntlはfile controlの略
    // あらゆる種類のファイルを制御できる関数(ソケットもファイルとみなされる)
    // int fcntl(int socket, int command, long argument)
    // command: F_GETFL ... 現在のフラグを確認する
    // argument: 0を指定する
    // command: F_SETOWN ... シグナルSIGIOを受け取るプロセスIDを指定する
    // argument: getpid() ... 自身のプロセスID
    // １つのソケットを複数のプロセスから参照している可能性があるため, この設定が必要
    if (fcntl(serv_sock, F_SETOWN, getpid()) < 0) exit(EXIT_FAILURE);

    // command: F_SETFL ... フラグの値を変更/設定する場合に指定する
    // argument: O_NONBLOCK ... ソケットの動作をノンブロッキングに変更するフラグ
    // argument: FASYNC ... 準備が整ったということを伝えるフラグ
    if (fcntl(serv_sock, F_SETFL, O_NONBLOCK | FASYNC) < 0) exit(EXIT_FAILURE);

    for (;;) use_idle_time();
}

void use_idle_time()
{
    puts(".");
    sleep(3);
}

// シグナルSIGIOによりパケットの到着が通知されると, この関数がバックグラウンドで実行される
void sig_io_handler(int signal_type)
{
    struct sockaddr_in clnt_addr;
    unsigned int clnt_addr_len = sizeof(struct sockaddr_in);
    int recv_msg_size;
    char recv_buf[MSG_MAX_LEN];

    do {
        // ノンブロッキングにしたことによって発生したエラーの場合, errnoにEWOULDBLOCK(環境によってはEAGAIN)が設定される
        if ((recv_msg_size = recvfrom(serv_sock, recv_buf, MSG_MAX_LEN, 0, (struct sockaddr *)&clnt_addr, &clnt_addr_len)) < 0) {
            if (errno != EWOULDBLOCK) exit(EXIT_FAILURE);
        } else {
            printf("Handling client: %s\n", inet_ntoa(clnt_addr.sin_addr));
            if (sendto(serv_sock, recv_buf, recv_msg_size, 0, (struct sockaddr *)&clnt_addr, sizeof(struct sockaddr_in)) != recv_msg_size) exit(EXIT_FAILURE);
        }
    } while (recv_msg_size >= 0);
}