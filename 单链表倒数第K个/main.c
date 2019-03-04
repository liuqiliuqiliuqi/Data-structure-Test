#include<stdio.h>
#include"LinkList.h"

int main()
{
	 LinkList list;
	 InitLinkList(&list);
	 InsertElemToList(&list, 1, 0);
	 InsertElemToList(&list, 2, 1);
	 InsertElemToList(&list, 3, 2);
	 InsertElemToList(&list, 4, 3);
	 InsertElemToList(&list, 5, 4);

	 ShowList(&list);
	 printf("%d\n", Foundk(&list, 2));

	 printf("%d\n", Foundk(&list, 4));
	 reverse(&list);
	 ShowList(&list);
	 MakecircleList(&list);

	  Iscircle(&list);


	 LinkList list1;
	 LinkList list2;
	 InitLinkList(&list1);
	 InsertElemToList(&list1, 1, 0);
	 InsertElemToList(&list1, 2, 1);
	 InsertElemToList(&list1, 3, 2);
	 InsertElemToList(&list1, 4, 3);
	 InsertElemToList(&list1, 5, 4);
     InitLinkList(&list2);
	 InsertElemToList(&list2, 1, 0);
	 InsertElemToList(&list2, 2, 1);
	 InsertElemToList(&list2, 3, 2);
	 InsertElemToList(&list2, 4, 3);
	 InsertElemToList(&list2, 5, 4);

	 cross(&list1, &list2);
	 MakeIntersectList(&list1,&list2);
	 cross( &list1,  &list2);

}
