// never型
// 発生し得ない値の型を表現する

function error(message: string): never {
    throw new Error(message);
}

function infiniteLoop(): never {
    while (true) {}
}