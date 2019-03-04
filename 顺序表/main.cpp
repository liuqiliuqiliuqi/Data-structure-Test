#include "SqList.h"


int main()
{
	SqList list;  
	InitSqList(&list);
	InsertSqList(&list, 0, 10);
	InsertSqList(&list, 1, 11); 
	InsertSqList(&list, 2, 12);
	InsertSqList(&list, 3, 13);

	 Show(&list);

	 //ReverseSqlist(&list);
	 //printf("\n");
	 //Show(&list);

	 Func(&list, 12);
	 printf("\n");
	 Show(&list);


	/*InsertHead(&list, 9);
	InsertTail(&list, 14);
	
	

	FindVal(&list, 11);
	FindVal(&list, 10);

	DeleteSqList(&list, 2);
	DeleteHead(&list);
	DeleteTail(&list);

	FindVal(&list, 11);
	FindVal(&list, 10);


	DestroySqList(&list);

	*/

}