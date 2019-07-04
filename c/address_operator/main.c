#include <stdio.h>

int main(int argc, char *argv[]) {

    int a;
    double b;
    char c;

    // %p ... ポインタの値を表示するための変換指定子
    // &演算子 ... 変数のアドレスを取得する演算子
    // ちなみに, 正しくは%pで表示する際はvoidポインタを渡す必要があるためキャストしたほうが良い
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);

    a = 1;
    b = 1;
    c = 1.0;

    // 代入してもアドレスは変わらない
    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);

    char s[] = "hello, world!";

    // アドレスを見ると４バイトずつ進んでいることが分かる
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);

    // どちらも配列の0番目の要素のアドレスを指している
    printf("%p\n", s);
    printf("%p\n", &s);

    // %s で表示するときは第二引数にアドレスを渡す
    // s[0]では駄目. この場合は%cにする必要がある.
    printf("%s\n", &s[0]);  // hello, world!
    printf("%s\n", &s[1]);  // ello, world!

    return 0;
}