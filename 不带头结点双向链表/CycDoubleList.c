#include "CycDoubleList.h"

void InitCycDoubleList(pCycList list)
{
	assert(list != NULL);
	list->head = NULL;
	list->count = 0;
}

static CycNode *BuyNode(ElemType value, CycNode *prev, CycNode* next)
{
	CycNode * s = (CycNode *)malloc(sizeof(CycNode));
	assert(s != NULL);

	s->data = value;

	if (prev == NULL || next == NULL)
	{
		s->next = s->prev = s;
	}
	else
	{
		s->next = next;
		s->prev = prev;
	}

	return s;
}

static void Insert(ElemType value, pCycList list, CycNode* p)
{
	CycNode *s = BuyNode(value, p, p->next);

	p->next->prev = s;
	p->next = s;

	list->count++;
}

void InsertCycDoubleList(pCycList list, ElemType value, int pos)
{
	assert(list != NULL);

	if (list->head == NULL)
	{
		CycNode *s = BuyNode(value, NULL, NULL);
		list->head = s;
		list->count++;
		return;
	}

	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	CycNode *p = list->head;

	if (pos == 0)
	{
		p = p->prev;
		Insert(value, list, p);
		list->head = list->head->prev;
	}
	else
	{
		while (pos > 1)
		{
			p = p->next;
			pos--;
		}

		Insert(value, list, p);
	}
}

void DeleteCycDoubleList(pCycList list, int pos)
{
	assert(list != NULL && list->head != NULL);

	if (list->head->next == list->head)
	{
		free(list->head);
		list->head = NULL;
		list->count--;
		return;
	}

	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	CycNode *p = list->head;

	if (pos == 1)
	{
		while (p->next != list->head)
		{
			p = p->next;
		}

		list->head = list->head->next;
	}
	else
	{
		while (pos > 2)
		{
			p = p->next;
			pos--;
		}
	}

	CycNode *q = p->next;
	p->next = q->next;

	free(q);
	list->count--;
}

void ShowDoubleList(pCycList list)
{
	assert(list != NULL && list->head != NULL);

	CycNode *p = list->head;

	while (p->next != list->head)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("%d  \n", p->data);
}