#include "test.h"

struct ListNode{
	int val;
	struct ListNode *next;
};
struct ListNode* addTwoNumbersV2(struct ListNode* l1, struct ListNode* l2) { 
	int carryFlag=0;
	struct ListNode *re = (struct ListNode*)malloc(sizeof(struct ListNode)),*q=re;
	re->next=NULL;
	while(l1!=NULL || l2!=NULL){
		q->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		q->next->next=NULL;
		int x=l1!=NULL?l1->val:0;
		int y=l2!=NULL?l2->val:0;
		q->next->val=(x+y+carryFlag)%10;
		printf("%d\n",q->val);
		carryFlag=(x+y+carryFlag)/10;
		q=q->next;
		if(l1!=NULL)
			l1=l1->next;
		if(l2!=NULL)
			l2=l2->next;
	}
	if(carryFlag!=0){
		q->next=(struct ListNode*)malloc(sizeof(struct ListNode));
		q->next->next=NULL;
		q->next->val=carryFlag;
	}
	q=re->next;
	free(re);
	return q;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {    
	int carryFlag=0;
	struct ListNode *re = (struct ListNode*)malloc(sizeof(struct ListNode)),*q=re;
	re->next=NULL;
	while(l1!=NULL && l2!=NULL){
		q->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->next->next=NULL;
		q->next->val = (l1->val+l2->val+carryFlag)%10;
		printf("%d\n",q->next->val);
		carryFlag=(l1->val+l2->val+carryFlag)/10;
		q=q->next;
		l1=l1->next;
		l2=l2->next;
	}
	int temp=0;
	if(l1!=NULL){
		q->next=l1;
		while(carryFlag!=0 && q->next!=NULL){
			q=q->next;
			temp=(q->val+carryFlag)/10;
			q->val=(q->val+carryFlag)%10;
			carryFlag=temp;
		}
	}else if(l2!=NULL){
		q->next=l2;
		while(carryFlag!=0 && q->next!=NULL){
			q=q->next;
			temp=(q->val+carryFlag)/10;
			q->val=(q->val+carryFlag)%10;
			carryFlag=temp;
		}
	}
	if(carryFlag!=0){
		q->next= (struct ListNode*)malloc(sizeof(struct ListNode));
		q->next->next=NULL;
		q->next->val=carryFlag;
	}
	q=re->next;
	free(re);
	return q;
}

void printNode(struct ListNode *l){
	while(l!=NULL){
		printf("%d ->", l->val);
		l=l->next;
	}
	printf("\n");
}

int main(){
	int a[1]={1};//{7,6,5,9,4,9,3,8,9};
	int b[99]={9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};//{5,9,1,8,5,0,5,5,6};
	struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode)),*q=l1;
	q->val=*a;
	int i=1;
	while(i<1){
		q->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		q->next->val = *(a+i);
		q=q->next;
		i++;
	}
	q->next=NULL;
	printNode(l1);
	struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode)),*p=l2;
	p->val=*b;
	int j=1;
	while(j<100){
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p->next->val = *(b+j);
		p=p->next;
		j++;
	}
	p->next=NULL;
	printNode(l2);
	q=addTwoNumbersV2(l1,l2);
	printNode(q);
	return 0;
}