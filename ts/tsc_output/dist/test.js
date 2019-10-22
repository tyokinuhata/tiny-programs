"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// 通常, tsconfigが置かれているディレクトリ以下にあるファイルの全てがビルドされ, そのディレクトリに出力されるが,
// tsconfigに outDir と include を設定することで, JSのビルド対象のファイルと出力先を指定することができる
function test() {
    return 'test';
}
exports.test = test;
