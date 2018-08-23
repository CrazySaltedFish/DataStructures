/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：size.c
*   创 建 者：CrazySaltedFish
*   创建日期：2018年04月13日
*   描    述：
*
================================================================*/


#include "size.h"
int main()
{
	printf("int size:%d byte.\n",(int)sizeof(int));
	printf("float size:%d byte.\n",(int)sizeof(float));
	printf("long size:%d byte.\n",(int)sizeof(long));
	printf("char size:%d byte.\n",(int)sizeof(char));
	printf("void size:%d byte.\n",(int)sizeof(void));
	printf("int* size:%d byte.\n",(int)sizeof(int *));
	printf("float* size:%d byte.\n",(int)sizeof(float *));
	printf("long* size:%d byte.\n",(int)sizeof(long *));
	printf("char* size:%d byte.\n",(int)sizeof(char *));
	printf("void* size:%d byte.\n",(int)sizeof(void *));
	return 0;
}
