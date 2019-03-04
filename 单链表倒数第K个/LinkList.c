#include "LinkList.h"
#include<assert.h>

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

int Foundk(pList list, int k )
{
	
	Node *p = &list->head;
	Node *q = &list->head;

	int i = 0;
	for (; i < k; i++)
	{
		p = p->next;
	}

	while (p->next != NULL)
	{
		p = p->next;
		q = q->next;	
	}

	return q->next->data;
}

 void reverse(pList list)
{
	Node *p = list->head.next;
	Node *q = list->head.next->next;
	Node *r = list->head.next->next->next;

	p->next = NULL;

	while (r ->next!= NULL)
	{
		q->next = p;
		p = q;
		q = r;
		r = q->next;
	}
	q->next = p;
	r->next = q;
	list->head.next=r;

}

 void MakeIntersectList(pList list1, pList list2)   //制造相交单链表
 {
	 Node *p = &list1->head;
	 Node *s = &list2->head;


	 while (list1->count > 3)
	 {
		 p = p->next;
		 list1->count--;
	 }


	 while (list2->count > 2)
	 {
		 s = s->next;
		 list2->count--;
	 }

	 p->next = s;

 }

 void  cross(pList list1, pList list2)
 {
	 Node *p = &list1->head;
	 Node *q = &list2->head;

	 while (p->next != NULL)
	 {
		 p = p->next;
	 }
	 while (q->next != NULL)
	 {
		 q = q->next;
	 }
	 if (q == p)
	 { 
		 printf("they are crossing\n");
	 }
	 else
	 {
		 printf("they are not crossing\n");
	 }  

 }

 void MakecircleList(pList list)
 {
	 Node *p = &list->head;
	 
	 while (p->next!=NULL)
	 {
		 p = p->next;
		 list->count--;
	 }
	 p->next = list->head.next->next;
 }

 void Iscircle(pList list)
 {
	 Node *q = list->head.next;
	 Node *p = list->head.next->next;
	 Node *r = &list->head;
	 
	 while (p != q)
	 {
		 p = p->next;
		 if (p->next == NULL)
		 { 
			 printf(" 不是有环单链表");
			 return;
		 }
		 p = p->next;
		 if (p->next == NULL)
		 {
			 printf(" 不是有环单链表");
			 return;
		 }
		 q = q->next;
	 }
	
	 int num = 0;
	 while (r != p)
	 {
		 r = r->next;
		 p = p->next;
		 num++;
	 }
	 printf("是有环单链表，入环点为第%d个结点\n", num);
 }

