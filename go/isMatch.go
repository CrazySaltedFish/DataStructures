package main 

import (
	"fmt"
)

func isMatch(s string,p string) bool {
	if len(s)==0 {
		if len(p)==0 || p=="*" {
			return true
		}else {
			return false
		}
	}
	if len(p)==0 {
		if len(s)==0 {
			return true
		}else {
			return false
		}
	}
	chs,chp := s[0],p[0]
	if chs != chp {
		return false
	}
	i,j:=1,1
	for ;i<len(s)&&j<len(p);i++ {
		switch p[j] {
			case '*':
				if chp != s[i] {return false}
				
			case '.':
				if chp != s[i] {return false}
				j++
				chp = p[j]
			default:
				if p[j]!=s[i] {return false}
			 	chp = p[j]
				j++
		}
	}
	return true
}

func main(){
	var m map[string] string = map[string]string{}
	m["aa"]="a"
	m["aa"]="a*"
	m["ab"]=".*"
	m["aab"]="c*a*b"
	m["mississippi"]="mis*is*p*."
	for key,value := range m {
		fmt.Println(key,value,isMatch(key,value))
	}
}