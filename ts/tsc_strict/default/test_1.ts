// 暗黙的なany型はNGという内容の警告が出る
// これはtsconfig.jsonに strict: true を設定しているため, 型チェックが厳密になっている
// test_1.ts:9:22 - error TS7006: Parameter 'arg' implicitly has an 'any' type.
//
// 1 export function test(arg) {
//                        ~~~
//
//
// Found 1 error.
export function test(arg) {
    return arg
}