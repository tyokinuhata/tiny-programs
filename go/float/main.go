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
	fmt.Println(foo)

	// 浮動小数点数の種類
	// 倍精度浮動小数点数 ... メモリ多 精度高
	var hoge float64 = 3.1415926535
	// 単精度浮動小数点数 ... メモリ少 精度低
	// float32を使用する場合は必ず型を明示する必要がある
	var piyo float32 = 3.1415926535
	fmt.Println(hoge, piyo)

	third := 1.0 / 3
	// Print, Printlnでは可能な限り多くの桁数を表示する
	fmt.Println(third)
	// それが望ましくない場合はPrintfを使用する
	fmt.Printf("%f\n", third)
	fmt.Printf("%.3f\n", third)
	// %4.2f ... %4: 幅, 2f: 精度
	// 幅 ... 表示したい最小文字数. 整数部 + 小数点 + 小数部
	// 精度 ... 小数の表示桁数
	fmt.Printf("%4.2f\n", third)
	// ゼロパディング
	fmt.Printf("%05.2f\n", third)

	// 計算機イプシロン(機械イプシロン)
	// 個の浮動小数点演算における丸め誤差の上限
	// float64 ... 2^-52
	// float32 ... 2^-23
}