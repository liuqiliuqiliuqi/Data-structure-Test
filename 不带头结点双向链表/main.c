#include "CycDoubleList.h"

int main()
{
	struct CycDoubleList list;

	InitCycDoubleList(&list);

	for (int i = 0; i < 5; ++i)
	{
		InsertCycDoubleList(&list, i * 10, i);
	}

	DeleteCycDoubleList(&list, 1);

	ShowDoubleList(&list);

}