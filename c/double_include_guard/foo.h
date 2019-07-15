// ヘッダファイルに書くべきこと
// - 単体で動作するようにする(必要なヘッダファイルをincludeしておく)
// - 二重include防止用のガードをかける(二重定義だとエラーが出る)
#ifndef FOO_H_INCLUDED
#define FOO_H_INCLUDED
// something ...
#endif