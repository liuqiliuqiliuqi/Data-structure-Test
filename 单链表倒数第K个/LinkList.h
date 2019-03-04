#ifndef __LINKLIST_H
#define __LINKLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>


typedef int ElemType;


typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;



typedef struct LinkList
{
	struct Node head; 
	int count;
}LinkList, *pList;



void InitLinkList(pList list);

void InsertElemToList(pList list, ElemType val, int pos);

void DeleteElemOfList(pList list, int pos);

void ShowList(pList list);

int Foundk(pList list, int num);

void reverse(pList list);

void MakeIntersectList(pList list1, pList list2);

void  cross(pList list1, pList list2);

void MakecircleList(pList list);

void Iscircle(pList list);


#endif