// TCPサーバ
// selectによる多重化

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>
#include "tcp_server.h"

// ./a.out 5 1 2 3 4 5
// ./a.out <タイムアウト> <ポート１> <ポート２> <ポート３> ...
// のフォーマットで指定する
int main (int argc, char **argv)
{
    if (argc < 3) exit(EXIT_FAILURE);

    // コマンドライン引数で指定されたタイムアウトの値
    long timeout = atol(argv[1]);

    // ポート数
    // -2 はargv[0]のファイル名とargv[1]のタイムアウト分
    int port_num = argc - 2;

    // ソケットのリスト
    int *serv_sock = (int *)malloc(port_num * sizeof(int));

    int serv_port;
    // ソケットディスクリプタの最大値(最大値が0より小さくなることはないので初期値は-1)
    int max_descriptor = -1;
    for (int i = 0; i < port_num; i++) {
        // コマンドライン引数で受け取ったポート番号を数値に変換
        serv_port = atoi(argv[i + 2]);
        // ソケットの作成 -> バインド -> リッスン
        if((serv_sock[i] = setup_tcp_serv_sock(serv_port)) < 0) exit(EXIT_FAILURE);
        // ソケットディスクリプタの最大値を更新
        if (serv_sock[i] > max_descriptor) max_descriptor = serv_sock[i];
    }

    puts("Starting server: Hit return to shutdown");

    // サーバが動作中かどうか
    int is_run = true;
    // select関数の対象となるソケットディスクリプタをセットする変数
    fd_set sock_set;
    // timeval構造体
    // time_t tv_sec(秒) と time_t tv_usec(マイクロ秒) の２つのフィールドを持つ
    struct timeval sel_timeout;
    while (is_run) {
        // FD_XXXXマクロはディスクリプタのリストを操作を提供するマクロ
        // ディスクリプタのリスト(≒fd_set型のベクタビット)
        // FD_ZERO
        // ディスクリプタのリストを0に初期化する
        // FD_ZERO(fd_set *descriptorVector)
        // select関数を実行する度にリセットが必要
        FD_ZERO(&sock_set);
        // FD_SET
        // ディスクリプタのリストに追加する
        // FD_SET(int descriptor, fd_set *descriptorVecror)
        // 以下ではディスクリプタのリストに標準入力(キーボード)を追加している
        // ちなみにディスクリプタとは ... プログラムがアクセスするファイルや標準入出力等をOSが区別するための識別子
        FD_SET(STDIN_FILENO, &sock_set);
        for (int i = 0; i < port_num; i++) FD_SET(serv_sock[i], &sock_set);

        // タイムアウトの指定
        // select関数を実行する度にリセットが必要
        sel_timeout.tv_sec = timeout;
        sel_timeout.tv_usec = 0;

        // select関数
        // ノンブロッキングI/O ... サーバがソケットを継続的にポーリングするためオーバーヘッドが大きい
        // select関数を使えば, いずれかのソケットでI/Oが可能になった時点でサーバに処理のブロックをやめさせることができる
        // ディスクリプタのリストにあるいずれかのディスクリプタでI/Oが可能になるまでプログラムを一時停止し, 利用可能になったディスクリプタに関する情報を返す
        // int select(int maxDescPlus1, fd_set *readDescs, fd_set *writeDescs, fd_set *exceptionDescs, struct timeval *timeout)
        // readDescs ... データが直ちに入力可能である場合にチェックされるディスクリプタのリスト
        // writeDescs ... データが直ちに出力可能である場合にチェックされるディスクリプタのリスト
        // exceptionDescs ... ペンディング中の例外をチェックするディスクリプタのリスト
        // timeout ... tv_secとtv_usecの両方が0の場合, ポーリングを有効にして直ちに処理を戻す
        // NULLが渡されたディスクリプタのリストはチェックしない
        // ディスクリプタのリストがいずれもI/O可能にならないずにタイムアウトしたならば0を返す
        // I/Oが可能の場合は可能になったディスクリプタの合計数を返す
        if (select(max_descriptor + 1, &sock_set, NULL, NULL, &sel_timeout) == 0) {
            printf("No echo requests for %ld secs ... Server still alive\n", timeout);
        }
        else {
            // FD_ISSET
            // ディスクリプタのリストに指定したディスクリプタが含まれているかどうか
            // FD_ISSET(int descriptor, fd_set *descriptorVector)
            // 他にも FD_CLR(int descriptor, fd_set *descriptorVector) 指定したディスクリプタを削除する もある
            if (FD_ISSET(STDIN_FILENO, &sock_set)) {
                printf("Shutting down server\n");
                getchar();
                is_run = false;
            }

            for (int i = 0; i < port_num; i++) {
                if (FD_ISSET(serv_sock[i], &sock_set)) {
                    printf("Request on port: %d\n", i);
                    echo_back(ac_tcp_serv_con(serv_sock[i]));
                }
            }
        }
    }

    // 終了処理
    for (int i = 0; i < port_num; i++) close(serv_sock[i]);
    free(serv_sock);
    exit(EXIT_SUCCESS);
}