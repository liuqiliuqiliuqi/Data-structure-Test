#include "Stack.h"

int main()
{
	Stack stack;

	InitStack(&stack);
	/*
	for (int i = 0; i < 12; ++i)
	{
	if (!Push(&stack, i))
	{
	printf("push fail\n");
	DestoryStack(&stack);
	return 0;
	}
	}

	ElemType val;
	while (Pop(&stack, &val))
	{
	printf("%d\n", val);
	}

	DestoryStack(&stack);

	Push(&stack, 10);*/

	/*char *s = "£¨3*[5+4]*{[3+5]*[40-2*(5-3)]}£©";
	if (Match(s))
	{
		printf("À¨ºÅÆ¥Åä\n");
	}
	else
	{
		printf("À¨ºÅ²»Æ¥Åä\n");
	}
	return 0;
*/
	char *str = "435*+23*-";
	ElemType val = BoLan(&stack, str);
	printf("%d", val);

}