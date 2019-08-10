// TCPクライアント
// クライアントとサーバでTCPで通信を行うサンプル
// アプリケーション層のプロトコルにはEcho Protocolを使用する
// Echo Protocolは受信したデータのコピーを返信する
// TCP/UDPポート番号は7

// TCPサーバ
// サーバにはNetCatを使用して検証した
// Macにデフォで入っているncには-eオプションが無く, 任意のコマンドを実行できないため, brew install netcatでインストール
// netcat -l 127.0.0.1 -p 7 -e /bin/cat -vv
// -vv ... 情報を詳細に出力する
// ncには-kオプションで複数のコネクションを張ることができるが(ただしMac版では動作しなかった), netcatには無さそう

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// socket関数, connect関数, send関数, recv関数を使うために必要
#include <sys/socket.h>
// sockaddr_in, inet_addr関数を使うために必要
#include <arpa/inet.h>
// close関数を使うために必要
#include <unistd.h>

// 受信バッファのサイズ
#define RECV_BUF_SIZE 32

// ./a.out 127.0.0.1 'hello, world!'
// ./a.out 127.0.0.1 'hello, world!' 7
int main (int argc, char **argv)
{
    // コマンドライン引数のチェック
    if (argc < 3 || argc > 4) exit(EXIT_FAILURE);

    // サーバのIPアドレスと送信するメッセージの設定
    char *serv_ip = argv[1];
    char *send_msg = argv[2];

    // サーバのポート番号の設定
    unsigned short serv_port = 7;
    if (argc == 4) serv_port = atoi(argv[3]);

    // ソケットの作成
    // int socket(int protocolFamily, int type, int protocol)
    // protcocolFamily ... プロトコルスタックの指定. TCP/IPプロトコルスタックを使用する場合は PF_INET を指定する
    // type ... ソケットの種類の指定. SOCK_STREAM(信頼性の高い転送), SOCK_DGRAM(ベストエフォート型)
    // protocol ... エンドツーエンドプロトコルの指定. PF_INETを指定した場合, IPPROTO_TCP(TCP)かIPPROTO_UDP(UDP)を指定する.
    //              定数0を指定した場合はプロトコルスタックとソケットの種類から選択されるが, 将来的に新しいエンドツーエンドプロトコルが追加される可能性があるため, 原則記述する.
    //              成功時には正の整数, 失敗時には-1を返す
    //              成功時に返される値はソケットディスクリプタと呼ばれる数値で, ソケットAPI関数内で処理されるソケットの識別に利用される
    int sock;
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) exit(EXIT_FAILURE);

    // アドレスファミリを定義する構造体の作成
    // sockaddr構造体をTCP/IPプロトコルスタック用に特化させたものがsockaddr_in構造体
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr)); // ゼロクリア. 処理系によっては必要が無い場合もある
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(serv_ip); // inet_addr関数はドット10進表記のIPアドレスを32ビットの2進数表現に変換する
    serv_addr.sin_port = htons(serv_port); // ポート番号を適切な型に変換

    // サーバへの接続を確立
    // int connect(int socket, struct sockaddr *foreignAddress, unsigned int addressLength)
    // socket ... socket関数で作成したソケットディスクリプタ
    // foreignAddress ... sockaddr構造体へのポインタ
    // 成功するとソケットの接続が確立する
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in))) exit(EXIT_FAILURE);

    // 文字列をサーバへ送信
    // int send(int socket, const void *msg, unsigned int megLength, int flags)
    // msg ... 送信する文字列へのポインタ
    // msgLength ... 送信する文字列の長さ
    // flags ... 0を指定するとデフォルトの振る舞いをする
    // send関数を実行するとデータが全て送信されるまでプログラムは一旦停止する
    int send_msg_len = strlen(send_msg);
    if (send(sock, send_msg, send_msg_len, 0) != send_msg_len) exit(EXIT_FAILURE); // 区切り文字\0は送信されない

    // 同じ文字列をサーバから受信
    int recv_msg_byte = 0, recv_msg_total_byte = 0;
    char recv_buf[RECV_BUF_SIZE];
    printf("Received: ");
    while (recv_msg_total_byte < send_msg_len) {
        // int recv(int socket, const void *rcvBuffer, unsigned int bufferLength, int flags)
        // rcvBuffer ... 受信するデータを格納するバッファへのポインタ
        // bufferLength ... 一度に受信可能なバイト数の最大値
        // flags ... send関数と同じ
        // recv関数はデータが利用可能になるまでプログラムの実行をブロックする
        // データ受信後は成功時にバッファにコピーしたデータのバイト数、失敗時に-1を返す
        if ((recv_msg_byte = recv(sock, recv_buf, RECV_BUF_SIZE, 0)) <= 0) exit(EXIT_FAILURE);
        recv_msg_total_byte += recv_msg_byte;
        recv_buf[recv_msg_byte] = '\0';
        printf("%s", recv_buf);
    }
    puts("");

    // 切断
    close(sock);
    exit(EXIT_SUCCESS);

    // クライアントの処理の流れは, socket -> connect -> send -> recv -> close の順
}