// any型
// 型の不明な変数に付与する型
// 特定の値の型チェックを無効にし, コンパイラを通過させることができる
// 既存のJSプロジェクトからの移行時には有効だが, TSの恩恵を受けられないため, できる限り使用は控える
let whatever: any = 0;
whatever = "something";
whatever = false;