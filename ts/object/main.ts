// object型
// 非プリミティブ型を表す型
let obj1: {}
let obj2: object

// {}を使った型表現では, エラーを得ることができない
obj1 = true
obj1 = 0

// こっちはエラー
// obj2 = true
// obj2 = 0