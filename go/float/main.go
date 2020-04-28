package main

import "fmt"

func main() {
	// 以下の３つは全て等価
	// 型を明示しなくともGoのコンパイラが推論するため
	float1 := 3.1415926535
	var float2 = 3.1415926535
	var float3 float64 = 3.1415926535
	fmt.Println(float1, float2, float3)

	// 以下のように明示的に型を指定して変数を初期化した場合は, たとえ整数であろうとも浮動小数点として扱われる
	var foo float64 = 3

	// 浮動小数点数の種類
	// 倍精度浮動小数点数 ... メモリ多 精度高
	var hoge float64 = 3.1415926535
	// 単精度浮動小数点数 ... メモリ少 精度低
	// float32を使用する場合は必ず型を明示する必要がある
	var piyo float32 = 3.1415926535
}