#include <stdio.h>

void output_string(void *);

int main(int argc, char *argv[]) {
    int n = 65;
    double f = 3.14;

    output_string(&n);
    output_string(&f);

    return 0;
}

// voidポインタ
// どんなデータ型のポインタでも格納できる
void output_string(void *v) {
    // もちろんサイズは違うので結果は保証されない
    // ただエラーは出ない
    char *s = (char *)v;
    printf("%s\n", s);
}