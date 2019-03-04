#include "LinkList.h"

int main()
{
	LinkList list; 
	InitLinkList(&list);
   InsertElemToList(&list, 10, 0);
   InsertElemToList(&list, 10, 1); 
   InsertElemToList(&list, 10, 2);
 
	 DeleteElemOfList(& list, 1);
	DeleteElemOfList(& list, 1);

	 ShowList(&list);
}