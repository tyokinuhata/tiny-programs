package main

import "fmt"

func main()  {
	// 比較演算子

	var age = 20
	// == 等しい, != 等しくない, < より小さい(未満), > より大きい(超過), <= 以下, >= 以上
	var minor = age < 18	// false
	fmt.Println(minor)
}