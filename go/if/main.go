package main

import "fmt"

func main()  {
	var score = 80

	// if分岐
	// if〜else if〜else
	if score > 80 {
		fmt.Println("good!")
	} else if score > 30 {
		fmt.Println("so so ...")
	} else {
		fmt.Println("bad!")
	}
}