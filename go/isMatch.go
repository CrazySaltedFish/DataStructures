package main 

import (
	"fmt"
)

func isMatch(s string,p string) bool {
	if p=="*" || p==".*" {
		return true
	}
	if len(s)==0 {
		if len(p)==0 {
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
	for ;i<len(s) && j<len(p); {
		if s[i] == p[j] {
			chp=p[j]
			i++
			j++
		}else if p[j]=='*' && s[i] == chp {
			i++
		} else if p[j] == '*' && j+1 < len(p) && s[i] == p[j+1] {
			chp = p[j+1]
			j=j+2
			i++
		}else{
			return false
		}
	}
	if i!=len(s)-1 {
		return false
	} 
	for ;j<len(s);j++ {
		if p[j] != '*' {
			return false
		}
	}
	return true
}

func main(){
	var m map[string] string = map[string]string{}
	m["aa"]="a"
	m["aa"]="a*"
	m["aan"]="*"
	m["ab"]=".*"
	m["aab"]="c*a*b"
	m["mississippi"]="mis*is*p*."
	for key,value := range m {
		fmt.Println(key,value,isMatch(key,value))
	}
}