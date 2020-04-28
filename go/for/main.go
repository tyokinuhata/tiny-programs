package main

import "fmt"

func main()  {
	var cnt = 10
	for cnt > 0 {
		fmt.Println(cnt)
		cnt--
	}

	// ループの途中で抜ける
	// break
	cnt = 10
	for cnt > 0 {
		fmt.Println(cnt)
		cnt--
		if cnt < 5 {
			break
		}
	}
}