// TCPサーバ
// 制限付きマルチタスク

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "tcp_server.h"

#define PROCESS_LIMIT 5

void ps_main(int);

int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 2) serv_port = atoi(argv[1]);

    // 待ち受け用のソケットの作成 -> バインド -> リッスン
    int serv_sock;
    if ((serv_sock = setup_tcp_serv_sock(serv_port)) < 0) exit(EXIT_FAILURE);

    pid_t ps_id;
    for (int ps_cnt = 0; ps_cnt < PROCESS_LIMIT; ps_cnt++) {
        // エラーの場合
        if ((ps_id = fork()) < 0) exit(EXIT_FAILURE);
        // 子プロセスの場合
        else if (ps_id == 0) ps_main(serv_sock);
    }

    // 親プロセスは子プロセスの生成後, 終了する
    exit(EXIT_SUCCESS);
}

void ps_main (int serv_sock)
{
    int clnt_sock;
    for (;;) {
        if ((clnt_sock = ac_tcp_serv_con(serv_sock)) < 0) exit(EXIT_FAILURE);
        printf("With child process: %d\n", (unsigned int)getpid());
        if (echo_back(clnt_sock) < 0) exit(EXIT_FAILURE);
    }
}