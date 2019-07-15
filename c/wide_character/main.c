#include <stdio.h>
// wchar_t型を使うために必要
#include <stddef.h>

int main () {

    // ワイド文字
    // s[i]のように書いても, 取り出すことができるのはnバイト目のバイトであって, 文字ではない
    // こういった問題をある程度解決できるのがワイド文字
    // char型は1バイトを表現するが, wchar_t型は1文字を表現する
    // Shift_JIS ... 1文字2バイト, UTF-8 ... 1文字3バイト => マルチバイト文字と呼ばれる
    // ワイド文字により構成される文字列(つまりwchar_t型の配列) => ワイド文字列

    // ""で囲んだ文字列の前にLを付けることでワイド文字列リテラルとなる
    // 𠮟 ... 「叱」ではない. サロゲートペア文字. 2バイトで表現できない文字列
    wchar_t s[] = L"日本語123𠮟";

    // wchar_t型のサイズ
    printf("%d\n", (int)sizeof(wchar_t)); // 4

    // 配列sの文字数
    // 8バイト. ただしWin環境だと9になる場合がある
    printf("%d\n", (int)(sizeof(s) / sizeof(s[0])));

    // また, wcscpy関数やwprintf関数, wcrtomb関数など, ワイド文字専用の関数が用意されている
}