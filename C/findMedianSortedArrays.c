#include "test.h"

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	//调整数组，使得num1的长度不大于num2
	if(nums1Size>nums2Size){
	 	int *temp=nums1;
	 	nums1=nums2;
	 	nums2=temp;
	 	int tmp=nums1Size;
	 	nums1Size=nums2Size;
	 	nums2Size=tmp;
	}   
	int iMin=0,iMax=nums1Size,halfLen=(nums1Size+nums2Size+1)/2;
	while(iMin<=iMax){
		int i=(iMin+iMax)/2;
		int j=halfLen-i;
		if(i<iMax && nums2[j-1]>nums1[i]){
			iMin=i+1; //i is too small
		}else if(i>iMin && nums1[i-1]>nums2[j]){
			iMax=i-1; //i is too big
		}else{
			int maxLeft=0;
			if(i==0){
				maxLeft=nums2[j-1];
			}else if(j==0){
				maxLeft=nums1[i-1];
			}else{
				maxLeft=nums1[i-1]>nums2[j-1]?nums1[i-1]:nums2[j-1];
			}
			if((nums1Size+nums2Size)%2 == 1){
				return maxLeft;
			}

			int minRight=0;
			if(i==nums1Size){
				minRight=nums2[j];
			}else if(j==nums2Size){
				minRight=nums1[i];
			}else{
				minRight=nums1[i]<nums2[j]?nums1[i]:nums2[j];
			}
			return (maxLeft+minRight)/2.0;
		}
	}
	return 0.0;
}

int main(){
	int nums1[]={1,2};
	int nums2[]={3,4};
	int nums1Size=2;
	int nums2Size=2;
	double a=findMedianSortedArrays(nums1,nums1Size,nums2,nums2Size);
	printf("%f\n", a);
	return 0;
}