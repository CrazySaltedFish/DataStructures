/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：test.c
*   创 建 者：CrazySaltedFish
*   创建日期：2018年04月13日
*   描    述：
*
================================================================*/


#include "test.h"
void a_plus(int *);
int main()
{
	int *a[3];
	int size=3;
	for(int i=0;i<size;i++){
		int *tmep=(int*)malloc(sizeof(int)*3);
		*(tmep+0)=i;
		*(tmep+1)=i+1;
		*(tmep+2)=i+2;
		*(a+i)=tmep;
	}
	for(int i=0;i<size;i++){
		for(int j=0;j<3;j++){
			printf("%d",*(*(a+i)+j));
		}
		printf("\n");
	}
	return 0;
}
void a_plus(int *a){
	*a++;
	printf("a_plus:%d",*a);
}
