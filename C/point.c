#include "test.h"
int main(){
	int array[10];
	for (int i = 0; i < 10; ++i)
	{	
		array[i]=0;
	}
	int array2[10],*ap;
	for (ap=array2;ap<array2 + 10;ap++)
	{
		*ap=0;
	}
	return 0;
}