package main

import "fmt"

func main() {
	var status = 400

	switch status {
	case 400:
		fmt.Println("Bad Request")
	case 401:
		fmt.Println("Unauthorized")
	case 403:
		fmt.Println("Forbidden")
	case 404:
		fmt.Println("Not Found")
	}

	// fallthroughを使うと次のcaseも実行される
	// CやJava, JS等の言語では次のcaseはデフォルトで実行される
	var foo = "foo"
	switch foo {
	case "foo":
		fmt.Println("foo!")
		fallthrough
	case "bar":
		fmt.Println("こっちも実行される")
	}
}