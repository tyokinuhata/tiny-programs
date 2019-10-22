// tsconfigで "noImplicitAny": false とされている場合, :any が付与されていなくてもエラーが発生しなくなる
export function test(arg) {
    return arg
}