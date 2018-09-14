package main

import (
	"fmt"
	"strings"
)

func myAtoi(str string) int {
    str=strings.TrimLeft(str," ")
    if len(str) <= 0 {
        return 0
    }
    ch := str[0]
    switch ch{
        case '+':
            return toInt(str[1:],false)
        case '-':
            return -toInt(str[1:],true)
        case '0','1','2','3','4','5','6','7','8','9':
            return toInt(str[0:],false)
        default:
            return 0
    }

}

func toInt(str string,isMinus bool) int{
    result :=0
    for i:=0;i<len(str);i++ {
        if str[i]<'0' || str[i]>'9' {
            break
        }
        result = result*10 + int(str[i])-48
	if result > 1 << 31 - 1 {
		if isMinus {
			return 1<<31 
		}else {
			return 1<<31 - 1
		}    
	}
    }
    return result
}

func main(){
	arr := [...] string {"-91283472332","word 90","43","   -42","9223372036854775808"}
	for index,value:= range arr {
		fmt.Println(index,myAtoi(value))
	}
}
