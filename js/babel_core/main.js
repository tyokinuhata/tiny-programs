// babel-core
// Babelの機能本体
// パーサー, トラバーサー, ジェネレーターの機能を全て持つ
const { transform } = require('@babel/core');

const src = '1 + 2';
const opts = { plugins: [] };

// code ... 変換後のソースコード
// ast ... 変換後のAST
// map ... ソースマップ
// ファイルから読み込む transformFile, transformFileSync, transformFromAst等の亜種もある
const { code, ast, map } = transform(src, opts);

console.log(src);
console.log(code);
console.log(ast);
console.log(map);