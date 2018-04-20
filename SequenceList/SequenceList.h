/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：SequenceList.h
*   创 建 者：CrazySaltedFish
*   创建日期：2018年04月20日
*   描    述：
*
================================================================*/

#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "../../Status/Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typeof int LElemType_Sq;
#endif

typeof struct
{
	LElemType_Sq *elem;	//存储空间基址（指向第一个结点的指针）
	int length;			//当前顺序表长度
	int listsize;		//
}SqList;

/*顺序表函数列表*/
Status InitList_Sq(SqList *L);
/*清空顺序表L*/
void ClearList_Sq(SqList *L);
/*销毁顺序表L*/
void DestroyList_Sq(SqList *L);
/*判断顺序表L是否为空*/
Status ListEmpty_Sq(SqList L);
/*返回顺序表L中元素个数*/
int ListLength_Sq(SqList L);
/*用e接收顺序表中第i个元素*/
Status GetElem_Sq(SqList L,int i,LElemType_Sq *e);
/*返回顺序表L中首个与e满足Compare关系的元素位序*/
int LocateElem_Sq(SqList l,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));
/*用pre_e接收cur_e的前驱*/
Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e);
/*用next_e接收cur_e的后继*/
Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e);
/*在顺序表L的第i个位置上插入e*/
Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e);
/*删除顺序表L上第i个位置的元素，并用e返回*/
Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e);
/*用visit函数访问顺序表L*/
Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq));

#endif


