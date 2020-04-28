package main

import "fmt"

func main() {
	const constant = "定数"
	var variable = "変数"

	fmt.Println(constant)
	fmt.Println(variable)

	// cannot assign to constant
	// constant = "後から代入できない"
	variable = "後から代入できる"

	fmt.Println(constant)
	fmt.Println(variable)

	// 宣言されていない変数に値を代入しようとするとエラーになる
	// undefined: foo
	// foo = "foo"
}