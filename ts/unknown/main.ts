// unknown型
// TS 3.0で追加された型
// 型安全なanyを表現できる
// const list1: number[] = ['0'];
const list2: any[] = ['0'];
const list3: unknown[] = ['0']

list2[0].toFixed(1)
// 以下はランタイムエラー(実行エラー)が発生する
// 値の代入には寛容だが, 値の利用に関しては厳しい
list3[0].toFixed(1)