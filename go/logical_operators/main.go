package main

import "fmt"

func main() {
	// 論理演算子
	// ||, &&, !

	// うるう年判定
	var year = 2100
	// 400で割り切れる または 4で割り切れてかつ100では割り切れない
	// 論理演算の切り詰め ... もし１つめの条件がtrueならば||に続く評価は無視される
	var is_leap = year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)
	if is_leap {
		fmt.Println("leap year")
	} else {
		fmt.Println("common year")
	}

	// 否定演算子
	var bool1 = true
	var bool2 = !bool1
	fmt.Println(bool1, bool2)
}