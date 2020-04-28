package main

import (
	"fmt"
	"math/rand"
)

// パッケージ内で有効なスコープを持つ
var foo = "foo"
// 省略宣言は使用できない
// syntax error: non-declaration statement outside function body
// foo := "foo"

func main()  {
	// 関数スコープ
	var count = 10
	for count > 0 {
		count--
		// forループ内のスコープ
		var n = rand.Intn(10) + 1
		fmt.Println(n)
	}

	// 関数内ならアクセスできる
	fmt.Println(count)
	// forループ内でのみアクセスできる
	// undefined: n
	// fmt.Println(n)
}