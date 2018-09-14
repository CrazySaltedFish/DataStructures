package main

import "fmt"

func init() {
	fmt.Println("hi,", bob)
}

func main() {
	fmt.Println("bye")
}

func init() {
	fmt.Println("hello,", smith)
}

func respectfulName(who string) string {
	return "Mr. " + who
}

var bob, smith = respectfulName("Bob"), respectfulName("Smith")
