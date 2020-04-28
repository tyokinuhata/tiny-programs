package main

import (
	"fmt"
	"strings"
)

func main()  {
	// ブール値
	var (
		bool1 = true
		bool2 = false
	)
	fmt.Println(bool1, bool2)

	// ブール値を返すメソッド
	var text = "foo bar baz"
	// textに"bar"という文字列が含まれているか
	var res = strings.Contains(text, "bar")
	fmt.Println(res)
}