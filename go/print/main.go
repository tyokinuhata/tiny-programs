package main

import "fmt"

func main() {
	fmt.Print("改行")
	fmt.Print("されない")

	fmt.Println("改行")
	fmt.Println("される")

	// スペース区切りで表示される
	fmt.Println("1 + 1 = ", 1 + 1, "です")

	// 整形付き出力
	// %v ... フォーマット指定
	fmt.Printf("1 + 1 = %v です", 1 + 1)

	fmt.Print("改行\nできます")
	fmt.Printf("改行\nできます\n")

	// テキストのアラインメント
	// %-15v ... 15文字の範囲を取って左寄せ
	// %4v ... 4文字の範囲を取って右寄せ
	fmt.Printf("%-15v $%4v\n", "foo", 100)
	fmt.Printf("%-15v $%4v\n", "barbaz", 1000)
}