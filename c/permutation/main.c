// Permutation
// 順列の数え上げ
// 順列 ... 異なるn個の中からr個を取り出して並べたときの全ての並べ方

// 順列は再帰を用いると簡潔に表現できる
// 他にも再帰を用いることで簡潔に表現できる例として, 木構造やグラフ構造がある

#include <stdio.h>

#define N 100

void print_result(void);
void permutation(int);

int used_flg[N + 1];
int result[N];
int n = 3, r = 3;

int main () {
    permutation(0);

    return 0;
}

void permutation(int nth) {
    if (nth == r) {
        print_result();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used_flg[i] == 0) {
            result[nth] = i;
            used_flg[i] = 1;
            permutation(nth + 1);
            used_flg[i] = 0;
        }
    }
}

void print_result() {
    for (int i = 0; i < r; i++) {
        printf("%d ", result[i]);
    }
    puts("");
}