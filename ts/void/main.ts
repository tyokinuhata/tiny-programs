// void型
// 型が全く無いことを表現する
function logger(message: string): void {
    console.log(message);
}

// void型の変数を宣言しても undefined か null を代入することしかできないため, 役に立たない
const unusable: void = undefined;