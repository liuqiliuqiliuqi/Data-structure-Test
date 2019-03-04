#include "Stack.h"

///////////////////////////////////
static void Expand(pStack stack)
{
	assert(stack != NULL);

	ElemType *s = (ElemType*)malloc(sizeof(ElemType)* stack->size * 2);
	assert(s != NULL);

	for (int i = 0; i < stack->top; ++i)
	{
		s[i] = stack->data[i];
	}

	free(stack->data);
	stack->data = s;
	stack->size *= 2;
}

static int IsFull(pStack stack)
{
	assert(stack != NULL);

	if (stack->top == stack->size)
	{
		return TRUE;
	}

	return FALSE;
}

static int IsEmpty(pStack stack)
{
	assert(stack != NULL);

	if (stack->top == 0)
	{
		return TRUE;
	}

	return FALSE;
}

////////////////////////////////////

void InitStack(pStack stack)
{
	assert(stack != NULL);

	stack->data = (ElemType *)malloc(sizeof(ElemType)* SIZE);
	assert(stack->data != NULL);

	stack->size = SIZE;
	stack->top = 0; //  -1
}

int Push(pStack stack, ElemType val)
{
	assert(stack != NULL);

	if (IsFull(stack))
	{
		Expand(stack);
		if (IsFull(stack))
		{
			return FALSE;
		}
	}

	stack->data[stack->top++] = val;

	return TRUE;
}

int Pop(pStack stack, ElemType *res)
{
	assert(stack != NULL);

	if (IsEmpty(stack))
	{
		return FALSE;
	}

	*res = stack->data[--stack->top];

	return TRUE;
}

void DestoryStack(pStack stack)
{
	assert(stack != NULL);

	free(stack->data);
	stack->data = NULL;
	stack->size = 0;
	stack->top = 0;
}

int Match(char *s)/*3.7 判断括号是否匹配*/
{
	int a = 0, b = 0, c = 0;
	while (*s != '\0')
	{
		if (*s == '(')
			a++;
		if (*s == ')')
			a--;
		if (*s == '[')
			b++;
		if (*s == ']')
			b--;
		if (*s == '{')
			c++;
		if (*s == '}')
			c--;
		if (a < 0 || b < 0 || c < 0)
		{
			return 0;
		}
		*s++;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BoLan(Stack *stack, char * str)/*3.8、编程对一个逆波兰式（后缀表达式）进行求值，如“435*+23*-”的结果是13*/
{
	char *p = str;
	ElemType left = 0;
	ElemType right = 0;

	while (*p != '\0')
	{
		if (isdigit(*p))
		{
			Push(stack, *p);
		}
		else if(*p == '+')
		{
			Pop(stack, &left);
			Pop(stack, &right);
			Push(stack, left + right - 48);

		}
		else if (*p == '-')
		{
			Pop(stack, &left);
			Pop(stack, &right);
			Push(stack,  right -left + 48);
		}
		else if (*p == '*')
		{
			Pop(stack, &left);
			Pop(stack, &right);
			Push(stack, (left - 48)* (right - 48) + 48);
		}
		else if (*p == '/')
		{
			Pop(stack, &left);
			Pop(stack, &right);
			Push(stack, (left - 48)/(right - 48) + 48);
		}
		*p++;
	}
	ElemType val;
	Pop(stack, &val);
	return val -48;
	
}








