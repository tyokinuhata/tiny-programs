#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// 同時にキューが可能な接続要求の最大数
#define MAX_PENDING 5
#define RECV_BUF_SIZE 32

void echo_back(int);

// ./a.out
// ./a.out 7
int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc > 2) exit(EXIT_FAILURE);

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 2) serv_port = atoi(argv[1]);

    // 待ち受け用のソケットの作成
    int serv_sock;
    if ((serv_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(struct sockaddr_in));
    serv_addr.sin_family = AF_INET;
    // 一般的にサーバのIPアドレスには INADDR_ANY を指定する
    // INADDR_ANYは通常は0.0.0.0が割り当てられている
    // 0.0.0.0 ... 無効なIPアドレスを表す
    // つまり, どの接続を受けるNICがどれでも良いということ
    // ちなみに, ローカルでのみ動かす場合, INADDR_LOOPBACK(つまり127.0.0.1)を指定することもできる
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // IPアドレスを適切な型に変換
    serv_addr.sin_port = htons(serv_port); // ポート番号を適切な型に変換

    // バインド
    // ソケットにポート番号, IPアドレスを割り当てる
    // クライアントでのconnectに当たる
    // int bind(int socket, struct sockaddr *localAddress, unsigned int addressLength)
    // 成功時には0, 失敗時には-1を返す
    // 指定したポートが既に使用済みの場合や, 処理系によってはウェルノウンポートに権限無しで指定した場合などに失敗することが多い
    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in)) < 0) exit(EXIT_FAILURE);

    // リッスン
    // ソケットの接続準備
    // クライアントからの接続要求を許可するよう, TCPの実装に伝える
    // listenを呼び出さない限り, そのソケットに対する接続要求(connect)は失敗する
    // int listen(int socket, int queueLimit)
    // queueLimit ... 接続要求を同時にいくつまでリッスンできるかの最大値. 処理系により意味合いが大きく異なるらしい.
    // 成功時には0, 失敗時には-1を返す
    if (listen(serv_sock, MAX_PENDING) < 0) exit(EXIT_FAILURE);

    struct sockaddr_in clnt_addr;
    unsigned int clnt_addr_len = sizeof(struct sockaddr_in);
    int clnt_sock;
    for (;;) {
        // accept
        // ソケットの接続待機
        // int accept(int socket, struct sockaddr *clientAddress, unsigned int *addressLength)
        // 新しいソケットが用意されるのを待っているクライアントからの接続要求がキューから取り出される
        // キューが空の場合, 接続要求が届くまでプログラムをブロックする
        // 戻り値は新しいソケットディスクリプタ
        // 処理に成功した場合, cliantAddressには接続元の情報が入る
        if ((clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_len)) < 0) exit(EXIT_FAILURE);

        // inet_ntoa関数
        // inet_addr関数 ... ドット10進表記のIPアドレス -> 32ビットの２進数表現 に変換
        // inet_ntoa関数 ... その逆で, 32ビットの２信州表現 -> ドット10進数表記のIPアドレス に変換
        // inet_ntop関数 ... inet_ntoa関数を拡張して複数のアドレスファミリを扱えるようにしたもの
        printf("Handling client: %s\n", inet_ntoa(clnt_addr.sin_addr));

        echo_back(clnt_sock);

        close(clnt_sock);
    }
}

// エコーバック
void echo_back (int clnt_sock)
{
    int recv_msg_len;
    char recv_buf[RECV_BUF_SIZE];
    if ((recv_msg_len = recv(clnt_sock, recv_buf, RECV_BUF_SIZE, 0)) < 0) exit(EXIT_FAILURE);

    while (recv_msg_len > 0) {
        if (send(clnt_sock, recv_buf, recv_msg_len, 0) != recv_msg_len) exit(EXIT_FAILURE);
        if ((recv_msg_len = recv(clnt_sock, recv_buf, RECV_BUF_SIZE, 0)) < 0) exit(EXIT_FAILURE);
    }
}