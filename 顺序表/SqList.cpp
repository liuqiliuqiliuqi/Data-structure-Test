#include "SqList.h"

/*
1、申请空间，并使list中elem指针指向这块空间
2、将list中length与listsize设置初始值

typedef struct
{
int *elem;   //  指向存储数据元素的空间的指针
int length;  //  当前存储数据的个数
int listsize;  //  当前分配的存储空间的大小
}SqList;
*/

static int IsEmpty(SqList *list)
{
	assert(list != NULL);

	if (list->length == 0)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsFull(SqList *list)
{
	assert(list != NULL);

	if (list->length == list->listsize)
	{
		return TRUE;
	}

	return FALSE;
}

static int ExpandSpace(SqList *list)
{
	assert(list != NULL);

	int change = list->listsize * 2;

	int * arr = (int *)malloc((list->listsize) * sizeof(int));

	for (int i = 0; i < list->listsize; i++)
	{
		arr[i] = list->elem[i];
	}

	list->listsize = list->listsize * 2;
	list->elem = (int *)malloc(list->listsize * sizeof(int));
	assert(list->elem != NULL);

	for (int j = 0; j < list->listsize / 2; j++)
	{
		list->elem[j] = arr[j];
	}
	
	return 1;

}

void InitSqList(SqList *list)
{
	assert(list != NULL);

	list->elem = (int *)malloc(sizeof(int)* LEN);
	list->length = 0;
	list->listsize = LEN;
	printf("init success\n");
}

void DestroySqList(SqList *list)
{
	assert(list != NULL);

	free(list->elem);
	list->length = list->listsize = 0;
	printf("Destroy success\n");
}

int InsertSqList(SqList *list, int pos, int val)
{
	assert(list != NULL);
	assert(pos >= 0);
	

	if (IsFull(list))
	{
		ExpandSpace(list);
	}
	if (pos <= list->length)
	{
		for (int i = pos; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = val;
			val = tmp;
		}
	}
	else if (pos == list->length + 1)
	{
		list->elem[pos] = val;
	}
	else
	{
		printf("insert error\n");
		return 0;
	}  

	list->length++;

	printf("insert success\n");

	return 1;
}

int InsertHead(SqList *list, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}

	if (IsEmpty(list))
	{
		list->elem[0] = val;
	}

	else
	{
		for (int i = 0; i < list->length + 1; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = val;
			val = tmp;
		}
	}
	
	list->length++;

	printf("insert success\n");

	return 1;

}

int InsertTail(SqList *list, int val)
{
	assert(list != NULL);

	if (IsFull(list))
	{
		ExpandSpace(list);
	}

	if (IsEmpty(list))
	{
		list->elem[0] = val;
	}
	else
	{
		list->elem[list->length] = val;
	}
	

	list->length++;

	printf("insert success\n");

	return 1;
}

int DeleteSqList(SqList *list, int pos)
{
	assert(list != NULL);
	assert(pos >= 0 && pos <= list->length); 
	assert(IsEmpty(list) == 0);

	for (int i = pos; i < list->length; i++)
	{
		int tmp = list->elem[i];
		list->elem[i] = list->elem[i + 1];
		list->elem[i + 1] = tmp;
	}
	

	list->length--;

	printf("delete success\n");

    return 1;
}

int DeleteHead(SqList *list)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("delete error:cannot find date\n");
		return 0;
	}

	if (list->length > 1)
	{
		for (int i = 0; i < list->length; i++)
		{
			int tmp = list->elem[i];
			list->elem[i] = list->elem[i + 1];
			list->elem[i + 1] = tmp;
		}
	}
	else
	{
		list->elem[0] = NULL;
	}

	list->length--;
	printf("delete success\n");
    return 1;
}

int DeleteTail(SqList *list)
{
	assert(list != NULL);

	if (IsEmpty(list))
	{
		printf("delete error:cannot find date\n");
		return 0;
	}

	list->elem[list->length - 1] = NULL;

	list->length--;
	printf("delete success\n");
	return 1;
}

int FindVal(SqList *list, int val)
{
	assert(list != NULL);
	int count = 0;
	int tmp = 0;

	if (IsEmpty(list))
	{
		printf("delete error:cannot find date\n");
		return 0;
	}

	for (int i = 0; i < list->length - 1; i++)
	{
		if (list->elem[i] == val)
		{
			count++;
			tmp = i;
			
		}

	}
	if (count == 0)
	{
		printf("cannot find\n");
	}
	else
	{
		printf("位置为%d\n", tmp);
	}
	
	return tmp;
}

void ReverseSqlist(SqList *list)/*11.顺序表逆置*/
{

	int i = 0;
	int j = list->length-1;
	for (; i <j; i++, j--)
	{
			int tmp = list->elem[i];
			list->elem[i] = list->elem[j];
			list->elem[j] = tmp;	
	}

}

void Func(SqList *list, int val)/*9.将数据插在有序的顺序表上依旧有序*/
{
	assert(list != NULL);

	int i = 0;
	int tmp = 0;
	for (; i < list->length; i++)
	{
		if (list->elem[i] >= val)
		{
			 tmp = list->elem[i];
			list->elem[i] = val;
			val = tmp;
		}
	}
	list->elem[i] = tmp;
	list->length++;
	
}

void Show(SqList *list)
{
	for (int i = 0; i <list->length; i++)
	{
		printf("%d  ", list->elem[i]);
	}
}