#include "test.h"
#include "quickSort.c"

int* twoSum(int* nums,int numsSize,int target){
	int tempCount=target+1;
	int* twoSum=(int*)malloc(sizeof(int)*2);
	int* tempArray=(int*)malloc(sizeof(int)*tempCount);
	for(int i=0;i<tempCount;i++){
		*(tempArray+i)=tempCount;
	}
	for(int i=0;i<numsSize;i++){
		if(*(nums+i)>target)
			continue;
		printf("%d\n",target-*(nums+i));
		if(*(tempArray+target-*(nums+i))!=tempCount){
			*twoSum=*(tempArray+target-i);
			*twoSum=i;
			return twoSum;
		}else{
			printf("%d\n",*(nums+i));
			*(tempArray+*(nums+i))=i;
		}
	}
	return NULL;
}

int main(){
	int nums[] = {2, 7, 11, 15}, size=4,target = 9;
	int *re= twoSum(nums,size,target);
	if(re==NULL)
		return 0;
	printf("[%d,%d]\n",*re,*(re+1));
	return 0;
}