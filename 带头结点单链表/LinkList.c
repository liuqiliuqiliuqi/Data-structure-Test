#include "LinkList.h"


static Node *BuyNode(ElemType val, Node *next)
{
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;
	s->next = next;

	return s;
}


void InitLinkList(pList list)
{
	list->count = 0;

	list->head.next = NULL;
}

void InsertElemToList(pList list, ElemType val, int pos)
{
	if (pos < 0 || pos > list->count)
	{
		printf("insert pos is error\n");
		return;
	}

	Node *s = (Node *)malloc(sizeof(Node));
	assert(s != NULL);

	s->data = val;

	Node *p = &list->head;

	while (pos > 0)
	{
		p = p->next;
		pos--;
	}

	s->next = p->next;
	p->next = s;

	list->count++;
}




void DeleteElemOfList(pList list, int pos)
{
	if (pos < 1 || pos > list->count)
	{
		printf("delete pos is error\n");
		return;
	}

	Node *p = &list->head;

	
	while (pos > 1)
	{
		p = p->next;
		pos--;
	}

	Node *q = p->next;
	p->next = q->next;

	free(q);

	list->count--;
}

void ShowList(pList list)
{
	assert(list != NULL);
	if (&list->head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	Node *p = &list->head;
	p = p->next;

	while (p->next != NULL)
	{
		printf("%d  ", p->data);
		p = p->next;
	}

	printf("%d  \n", p->data);
}