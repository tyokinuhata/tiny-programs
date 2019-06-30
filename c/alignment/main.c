#include <stdio.h>

struct tag_s {
    char c;
    double f;
};

int main(int argc, char *argv[]) {
    struct tag_s s;

    // char型は1byte, double型は8byteだが9byteにはならず16byteになる
    // これはアラインメントによるもので, 32bitのCPUであれば4byteずつ, 64bitのCPUであれば8byteずつ読み込む
    // 64bitのCPUの場合, 8の倍数になっていなければデータのアクセス効率が悪くなる
    // そのため, 8の倍数になるようにパディングされる
    printf("%zu\n", sizeof s);

    return 0;
}