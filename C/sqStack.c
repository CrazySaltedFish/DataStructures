#include "test.h"

#define ElemType int
#define MaxSize 10000

typedef struct{
	ElemType data[MaxSize];
	int top;
}SqStack;

// SqStack stack;

void InitStack(SqStack *S){
	S->top=-1;
}

bool StackEmpty(SqStack S){
	if(S.top==-1)
		return true;
	else
		return false;
}

bool Push(SqStack *S,ElemType x){
	if(S->top==MaxSize-1)
		return false;	//栈满
	S->data[++S->top]=x;
	return true;
}

bool Pop(SqStack *S,ElemType *x){
	if(S->top==-1)
		return false;	//栈空
	*x=S->data[S->top--];
	return true;
}

bool GetTop(SqStack S,ElemType *x){
	if(S.top==-1)
		return false;	//栈空
	*x=S.data[S.top];
	return true;

}

// int main(){
// 	SqStack *S=(SqStack*)malloc(sizeof(int)*(MaxSize+1));
// 	InitStack(S);
// 	Push(S,6);
// 	Push(S,9);
// 	Push(S,7);
// 	ElemType *x=(ElemType*)malloc(sizeof(int));
// 	Pop(S,x);
// 	printf("%d\n",*x);
// }
