package main

import (
	"fmt"
	"math/rand"
)

func main() {
	var foo = "foo"
	// 省略宣言
	bar := "bar"
	fmt.Println(foo, bar)

	// 省略宣言を使うとforループがスマートに書け, countのスコープも小さくなる
	for count := 10; count > 0; count-- {
		fmt.Println(count)
	}
	// ここではcountを参照できない
	// fmt.Println(count)

	if n := rand.Intn(10); n == 0 {
		fmt.Println("zero")
	} else {
		fmt.Println("not zero")
	}

	switch n := rand.Intn(10); n {
	case 0:
		fmt.Println("zero")
	default:
		fmt.Println("not zero")
	}
}