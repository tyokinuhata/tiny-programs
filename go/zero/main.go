package main

import "fmt"

func main() {
	// 明示的に初期化しない場合は0として初期化される
	var zero1 float64
	// ただし, 型を明示しない場合はエラーとなる
	// syntax error: unexpected newline, expecting type
	// var zero2
	// 以下は等価
	zero3 := 0.0
	fmt.Println(zero1, zero3)
}