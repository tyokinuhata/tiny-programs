"use strict";
// tsconfigに "declaration": true を指定することで,
// .d.tsという型宣言ファイルも出力されるようになる
// 通常の開発では使用する必要は無いが, ライブラリの開発等では, ライブラリの利用者に型を通達するために使用される
Object.defineProperty(exports, "__esModule", { value: true });
function test1() {
    return 'test';
}
exports.test1 = test1;
function test2() {
    return { value: 'test2' };
}
exports.test2 = test2;
