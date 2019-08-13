// TCPサーバ
// リクエスト毎にプロセスを生成する方式

#include <stdio.h>
#include <stdlib.h>
// fork関数, pid_t型を使うために必要
#include <unistd.h>
// waitpid関数を使うために必要
#include <sys/wait.h>
#include "tcp_server.h"

int main(int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 2) serv_port = atoi(argv[1]);

    // 待ち受け用のソケットの作成 -> バインド -> リッスン
    int serv_sock;
    if ((serv_sock = setup_tcp_serv_sock(serv_port) < 0)) exit(EXIT_FAILURE);

    int clnt_sock;
    pid_t process_id;
    unsigned int child_proc_cnt = 0;
    for (;;) {
        // accept
        if((clnt_sock = ac_tcp_serv_con(serv_sock)) < 0) exit(EXIT_FAILURE);

        // fork関数
        // pid_t fork(void)
        // 呼び出し元と全く同じプロセスを新しく生成する関数
        // fork関数を呼び出したプロセスは親プロセス, 呼び出して新たに生成されたプロセスは子プロセスと呼ばれる
        // プロセス生成後はそれぞれ別々のプロセスとして動作する
        // 戻り値は, 失敗時は-1, 親プロセスの場合は子プロセスのプロセスID, 子プロセスの場合は0
        if ((process_id = fork()) < 0) exit(EXIT_FAILURE);
        // 子プロセスの場合
        else if (process_id == 0) {
            // forkによって変数は受け継がれるが, 子プロセスでの変数の変更は親プロセスには影響しない
            // ソケットディスクリプタserv_sockはリッスンしているが, 子プロセスでリッスンする必要は無いのでcloseしておく
            // ただし親プロセスでもこのソケットディスクリプタを持っているため, このソケットの割り当て解除は行われない
            close(serv_sock);
            // エコーバック
            if(echo_back(clnt_sock) < 0) exit(EXIT_FAILURE);
            // 子プロセスの終了
            exit(EXIT_SUCCESS);
        }

        printf("With child process: %d\n", (int)process_id);
        // ソケットディスクリプタclnt_sockは親プロセスでは必要が無いのでcloseしておく
        // ただし親プロセスでもこのソケットディスクリプタを持っているため, このソケットの割り当て解除は行われない
        close(clnt_sock);
        child_proc_cnt++;

        // ゾンビプロセスの処理
        while (child_proc_cnt) {
            // waitpid関数
            // -1 ... ワイルドカードを意味する. プロセスIDに関わらず全てのゾンビプロセスを回収するよう指示している
            // NULL ... waitpid関数が返すゾンビプロセスの状態を格納するための変数. ここでは状態を返さないようにNULLを指定している
            // WNOHANG ... waitpid関数の動作をカスタマイズするためのパラメータ. WNOHANGを指定した場合, ゾンビプロセスが見つからなかった場合にすぐに制御を返す
            // 戻り値は, 失敗時に-1, ゾンビプロセスが見つかった場合にプロセスID, 見つからなかった場合に0を返す
            process_id = waitpid((pid_t)-1, NULL, WNOHANG);
            if (process_id < 0) exit(EXIT_FAILURE);
            else if (process_id == 0) break;
            else child_proc_cnt--;
        }
    }
}