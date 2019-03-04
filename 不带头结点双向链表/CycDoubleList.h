#ifndef __CYCDOULIST_H
#define __CYCDOULIST_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int ElemType;

typedef struct CycNode
{
	struct CycNode *prev;
	ElemType data;
	struct CycNode *next;
}CycNode;



typedef struct CycDoubleList
{
	CycNode *head;
	int count;
}CycDouList, *pCycList;

void InitCycDoubleList(pCycList list);

void InsertCycDoubleList(pCycList list, ElemType value, int pos);

void DeleteCycDoubleList(pCycList list, int pos);

void ShowDoubleList(pCycList list);

#endif