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

#endif