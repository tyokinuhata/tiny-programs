package main

import (
	"fmt"
	"math/rand"
)

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