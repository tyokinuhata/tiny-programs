// TCPサーバ
// クライアント毎にプロセスを新しく生成するのはコストが高い(tcp_server_processを参照)
// プロセスをコピーすると, 親プロセスのメモリ・スタック・ファイル/ソケットディスクリプタ等, 全ての状態がコピーされる
// そこでスレッドという仕組みを使って解決する
// スレッドは親と同じアドレス空間を共有するため, 親の状態をコピーする必要が無い

#include <stdio.h>
#include <stdlib.h>
// POSIXスレッド(PThread)を使うために必要
// POSIX標準のスレッド
// PThreadは移植性が高い
#include <pthread.h>
#include "tcp_server.h"

void *thread_main(void *);

// スレッドの引数として使用する構造体
typedef struct {
    int clnt_sock;
} t_thread_args;

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
    t_thread_args *thread_args;
    pthread_t thread_id;
    for (;;) {
        // accept
        if((clnt_sock = ac_tcp_serv_con(serv_sock)) < 0) exit(EXIT_FAILURE);

        if ((thread_args = (t_thread_args *)malloc(sizeof(t_thread_args))) == NULL) exit(EXIT_FAILURE);

        thread_args->clnt_sock = clnt_sock;

        // pthread_create関数
        // 新しくスレッドを生成する関数
        // int pthread_create(pthread_t *thread, pthread_attr_t *attr, void * (*start_routine)(void *), void *arg)
        // thread ... pthread_t型へのポインタを指定する. ここにスレッドIDが格納される
        // attr ... スレッドに適用する属性を指定する. NULLを指定した場合はデフォルトの属性が適用される
        // start_routine ... スレッドの実行時に使用する関数へのポインタを渡す
        // arg ... ここで指定した値がスレッドの第一引数となる
        // 戻り値は成功時に0, 失敗時に非0が返される
        if (pthread_create(&thread_id, NULL, thread_main, (void *)thread_args) != 0) exit(EXIT_FAILURE);

        printf("With thread: %ld\n", (long int)thread_id);
    }
}

// スレッド
void *thread_main (void *thread_args)
{
    // pthread_detach関数
    // スレッドが終了してメイン関数に制御が返っても, デフォルトではそのリソースが親に回収されるまで終了状態が保持される
    // pthread_detach関数はスレッドに割り当てられているリソースが終了時に直ちに開放される
    // int pthread_detach(pthread_t th)
    // th ... スレッドID
    // --------------------
    // pthread_self関数
    // プロセスがgetpid関数で自身のプロセスIDを得られるように, スレッドが自身のスレッドIDを取得できる
    pthread_detach(pthread_self());

    int clnt_sock = ((t_thread_args *)thread_args)->clnt_sock;

    echo_back(clnt_sock);

    return NULL;
}