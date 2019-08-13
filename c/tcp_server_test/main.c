// TCPサーバ
// リクエスト毎にプロセスを生成する方式

#include <stdio.h>
#include <stdlib.h>
// fork関数, pid_t型を使うために必要
#include <unistd.h>
// waitpid関数を使うために必要
#include <sys/wait.h>
#include "tcp_server.h"

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

    int clnt_sock;
    for (;;) {
        // accept
        if((clnt_sock = ac_tcp_serv_con(serv_sock)) < 0) exit(EXIT_FAILURE);

        echo_back(clnt_sock);

        close(clnt_sock);
    }
}