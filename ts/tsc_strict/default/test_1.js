"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// 暗黙的なany型はNGという内容の警告が出る
// test.ts:1:22 - error TS7006: Parameter 'arg' implicitly has an 'any' type.
//
// 1 export function test(arg) {
//                        ~~~
//
//
// Found 1 error.
function test(arg) {
    return arg;
}
exports.test = test;
