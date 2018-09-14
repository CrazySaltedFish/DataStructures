package main

import (
	"fmt"
)

func isPalindrome(x int) bool{
	if x<0 {
		return false
	}
	if x==reverse(x) {
		return true
	}
	return false
}

func reverse(x int) int{
	result := 0
	i:=0
	for{
		if x==0 {
			break
		}
		i=x%10
		result = result*10 + i
		x=x/10
	}
	return result
}

func main(){
	arr := [...] int {121,123,-121,10}
	for index,value := range arr {
		fmt.Println(index,value,isPalindrome(value))
	}
}
