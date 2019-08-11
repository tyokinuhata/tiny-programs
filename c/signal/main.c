// シグナル
// ユーザによる割り込み文字の入力やタイマーの期限切れといった特定のイベントの発声をプログラムに伝える仕組み
// シグナルにはデフォルトの動作が定義されており,
// 主に, 無視する・強制終了する・シグナル処理関数を実行する・ブロックする の４種類の振る舞いがある
// シグナルのデフォルトの動作は変更することができ(ただしできないものも存在する), その例がこのプログラムである

#include <stdio.h>
#include <stdlib.h>
// pause関数を使用するのに必要
#include <unistd.h>
// sigaction関数を使用するのに必要
#include <signal.h>

void interrupt_signal_handler(int);

int main(int argc, char **argv)
{
    // シグナルの動作を定義する構造体を宣言
    struct sigaction handler;

    // シグナル処理関数を設定
    // SIG_IGN ... 定数SIG_IGNを指定するとシグナルが無視されるようになる
    // SIG_DFL ... 定数SIG_DFLを指定するとシグナルに対するデフォルトの動作が適用される
    // 関数へのポインタを指定すると, 引数に送信されたシグナルを識別するパラメータが与えられ, その関数を呼び出す
    // この関数へのポインタの値は, SIG_IGNやSIG_DFLとは違う値であることが保証されている
    handler.sa_handler = interrupt_signal_handler;

    // sa_mask ... whichSignal(後述)を処理されている間にブロックするシグナルを指定する(関係無いシグナルをブロックするための仕組み)
    //             sa_handlerがSIG_IGNでもSIG_DFLでも無い場合にのみ有効となる
    //             sa_maskはsigset_t型で, １つがい種類のシグナルを扱うboolean型のフラグの集合として実装されている
    // sa_maskの操作には, 以下の４つの関数を用いる
    // int sigemptyset(sigset_t *set)                ... 全フラグをセット
    // int sigfillset(sigset_t *set)                 ... フラグをリセット
    // int sigaddset(sigset_t *set, int whichSignal) ... whichSignal(シグナル番号)で指定したフラグを個別にセットする
    // int sigdelset(sigset_t *set, int whichSignal) ... whichSignal(シグナル番号)で指定したフラグを個別にリセットする
    // いずれの関数も成功時に0, 失敗時に-1を返す
    if (sigfillset(&handler.sa_mask) < 0) exit(EXIT_FAILURE);

    // デフォルトの動作を変更するためのフラグ
    // デフォルトでは, whichSignalはsa_maskの指定に関わらずブロックされる
    // 環境によっては, sa_flagsにSA_NODEFERを指定することで処理中のシグナルの送信を可能にするものもある
    // また, sa_flagsではwhichSignalを更にきめ細かく制御することもできる
    handler.sa_flags = 0;

    // int sigaction(int whichSignal, const struct sigaction *newAction, struct sigaction *oldAction)
    // whichSignal ... 動作を変更させたいシグナル番号を指定する
    //                 例えば,
    //                 SIGALRM ... アラームタイマーの終了
    //                 SIGCHLD ... 子プロセスの終了
    //                 SIGINT  ... 割り込み文字(Ctrl + C)の入力
    //                 SIGIO   ... ソケットI/Oの準備完了
    //                 SIGPIPE ... クローズしたソケットへの書き込み
    // newAction ... sigaction構造体へのポインタ
    // oldAction ... sigaction構造体へのポインタ. NULL値で無い場合, 現在のsigaction構造体の値がコピーされてセットされる
    if (sigaction(SIGINT, &handler, 0) < 0) exit(EXIT_FAILURE);

    // シグナルを受け取るまでプログラムを一時停止させる
    for (;;) pause();

    exit(EXIT_SUCCESS);
}

// シグナル処理関数
void interrupt_signal_handler(int signal_type)
{
    puts("Interrupt received. Exiting program.");
    exit(EXIT_FAILURE);
}