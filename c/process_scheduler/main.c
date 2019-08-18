// プロセススケジューラの実験
// ./a.out <process_number> <total_usec> <statistics_collect_interval>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// err関数, warn関数を使うために必要
#include <err.h>
// timespec構造体, clock_gettime関数を使うために必要
#include <time.h>
// kill関数を使うために必要
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NLOOP_FOR_ESTIMATION 1000000000UL
#define NSECS_PER_MSEC 1000000UL
#define NSECS_PER_SEC 1000000000UL

static unsigned long loops_per_msec();
static inline long diff_nsec(struct timespec, struct timespec);
static void child(int, struct timespec *, int, unsigned long, struct timespec);
static inline void load(unsigned long nloop);

static pid_t *pids;

int main (int argc, char **argv)
{
    int ret = EXIT_FAILURE;

    // コマンドライン引数のチェック
    if (argc != 4) err(EXIT_FAILURE, "Wrong number of parameters.");

    // 同時に動作させるプロセス数
    int proc_num = atoi(argv[1]);
    // プロセスを動作させる合計時間(ミリ秒)
    int total_usec = atoi(argv[2]);
    // 統計時間の採取間隔(ミリ秒)
    int statistic_collect_interval = atoi(argv[3]);

    // 各パラメータが1以上の整数であるかのチェック
    if (proc_num < 1 || total_usec < 1 || statistic_collect_interval < 1) err(EXIT_FAILURE, "Invalid parameters.");

    // 割り切れるかどうかのチェック
    if (total_usec % statistic_collect_interval) err(EXIT_FAILURE, "<process total usec> should be multiple of <statistics collect number>");

    // 統計の採取回数の取得
    int statistic_collect_num = total_usec / statistic_collect_interval;

    // timespec構造体
    // time_t tv_sec(秒) と long tv_nsec(ナノ秒) で構成される
    // timeval構造体は long tv_sec(1970/1/1からの経過秒数. いわゆるエポック秒) と long tv_usec(ミリ秒) で構成される
    // timespec構造体はC11から追加された
    struct timespec *log_buf = malloc(statistic_collect_num * sizeof(struct timespec));

    // mallocできているかのチェック
    if (!log_buf) err(EXIT_FAILURE, "malloc(log_buf) failed.");

    puts("Estimating workload which takes just one milisecond.");
    unsigned long nloop_per_resol = loops_per_msec() * statistic_collect_interval;
    puts("End estimatation.");

    pids = malloc(proc_num * sizeof(pid_t));
    if (pids == NULL) {
        warn("malloc(pids) failed.");
        goto free_log_buf;
    }

    struct timespec start;
    // clock_gettime関数
    // 時刻を取得する関数
    // 第一引数で取得する時刻の種類を指定する
    // CLOCK_MONOTONICが指定された場合, ある開始時点からの単調増加の時間で表現されるクロック
    // int clock_gettime(clockid_t clk_id, struct timespec *tp)
    clock_gettime(CLOCK_MONOTONIC, &start);

    int ncreated = 0;
    for (int i = 0; i < proc_num; i++, ncreated++) {
        pids[i] = fork();
        // エラーの場合
        if (pids[i] < 0)        goto wait_children;
        // 子プロセスの場合
        else if (pids[i] == 0)  child(i, log_buf, statistic_collect_num, nloop_per_resol, start);
    }
    ret = EXIT_SUCCESS;

wait_children:
    if (ret == EXIT_FAILURE) {
        for (int i = 0; i < ncreated; i++) {
            if (kill(pids[i], SIGINT) < 0) warn("Kill(%d) failed.", pids[i]);
        }
    }
    for (int i = 0; i < ncreated; i++) {
        if (wait(NULL) < 0) warn("wait() failed.");
    }

// メモリの開放
free_pids:
    free(pids);

free_log_buf:
    free(log_buf);

// 終了処理
exit(ret);
}

// 適当な回数ループするのにどれぐらいの所要時間がかかったかの計測
unsigned long loops_per_msec ()
{
    struct timespec before, after;
    clock_gettime(CLOCK_MONOTONIC, &before);

    for (unsigned long i = 0; i < NLOOP_FOR_ESTIMATION; i++)
        ;

    clock_gettime(CLOCK_MONOTONIC, &after);

    return NLOOP_FOR_ESTIMATION * NSECS_PER_MSEC / diff_nsec(before, after);
}

// インライン関数
// inline修飾子の付いた関数のこと
// 一行程度の簡易的な関数に対して付けられることが多くマクロ関数の代替のような立ち位置
// 高速化のために関数を明示的にインライン展開させるための指示を与える
// インライン展開とは, コンパイル時に, 関数呼び出しの部分に呼び出し先の関数の内容が直接展開されること
// これにより関数呼び出しによるオーバーヘッドが無くなり, 高速化させることができる
// 従来はマクロ関数による高速化が使われていたが, マクロによる黒魔術はプログラマが予想しなかった結果を引き起こすことが多いという面がある
// コンパイラの最適化レベルが低かったり, コンパイラの制限に従っていない場合, インライン化されないため注意
static inline long diff_nsec (struct timespec before, struct timespec after)
{
    return ((after.tv_sec * NSECS_PER_MSEC + after.tv_nsec) - (before.tv_sec * NSECS_PER_MSEC + before.tv_nsec));
}

static void child (int id, struct timespec *buf, int nrecord, unsigned long nloop_per_resol, struct timespec start)
{
    for (int i = 0; i < nrecord; i++) {
        struct timespec ts;

        load(nloop_per_resol);
        clock_gettime(CLOCK_MONOTONIC, &ts);
        buf[i] = ts;
    }
    for (int i = 0; i < nrecord; i++) {
        printf("%d\t%ld\t%d\n", id, diff_nsec(start, buf[i]) / NSECS_PER_MSEC, (i + 1) * 100 / nrecord);
    }
    exit(EXIT_SUCCESS);
}

static inline void load (unsigned long nloop)
{
    for (unsigned long i = 0; i < nloop; i++)
        ;
}