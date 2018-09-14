#include "test.h"

#define SIZE 2000
char* longestPalindrome(char* s) {
	char new_s[SIZE];
	new_s[0]='$';
	new_s[1]='#';
	int i=0;
	int j=2;
	while(s[i++]!='\0'){
		new_s[j++]=s[i];
		new_s[j++]='#';
	}
	new_s[j]='\0';
	int len[j];
	int mx=-1;
	int t=0;
	int length=-1;
	int start,end;
	for(int k=1;k<j;k++){
		if(k<mx){
			len[k]=len[2*t-i]<(mx-i):len[2*t-i]:(mx-i);
		}else{
			len[k]=1;
		}
		while(k<j && new_s[k-len[k]]==new_s[k+len[k]]){
			len[k]++;
		}
		if(mx<len[k]+k){
			mx=len[k]+k;
			t=k;
		}
		if(length<len[k]-1){
			start=(k-len[k])/2;
			length=len[k]-1;
		}
	}

	char re[length];
	for(int l=0;l<length;l++){
		re[l]=
	}
}

int main(){
	return 0;
}