package main

import "fmt"

func main()  {
	// 色々な代入演算子

	var age = 21
	fmt.Println(age)
	// 複合代入演算子
	// -=, *=, /=等も使用できる
	age += 1
	fmt.Println(age)
	// 後置インクリメント演算子
	age++
	fmt.Println(age)
	// GoではCやJavaでサポートされているような前置インクリメント演算子はサポートされていない
	// ++age
	// fmt.Println(age)
	// 後置デクリメント演算子
	age--
	fmt.Println(age)
}