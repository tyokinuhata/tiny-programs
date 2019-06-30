#include <stdio.h>

void outputString(void *);

int main(int argc, char *argv[]) {
    int n = 65;
    double f = 3.14;

    outputString(&n);
    outputString(&f);

    return 0;
}

// voidポインタ
// どんなデータ型のポインタでも格納できる
void outputString(void *v) {
    // もちろんサイズは違うので結果は保証されない
    // ただエラーは出ない
    char *s = (char *)v;
    printf("%s\n", s);
}