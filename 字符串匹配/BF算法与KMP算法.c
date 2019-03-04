#include "list.h"
#include <string.h>

//  O(n*m)
int BF(const char *s, const char *p, int pos)
{
	assert(s != NULL && p != NULL);

	int lens = strlen(s);
	int lenp = strlen(p);

	if (lens < lenp)
	{
		return -1;
	}

	int i = pos, j = 0;

	while (i < lens && j < lenp)
	{
		if (s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;  // 使i回退到本次比较的初始位置的下一个位置
			j = 0;
		}
	}

	if (j >= lenp) // 如果j越界，证明比较时已经将p串访问完，则找到了相等的串
	{
		return i - j;
	}

	return -1;
}

//O(m)
void GetNext(const char *p, int *next)
{
	next[0] = -1;
	next[1] = 0;

	int j = 1;
	int k = 0;
	int lenp = strlen(p);

	while (j + 1 < lenp)
	{
		if (k == -1 || p[k] == p[j])
		{
// 			next[j + 1] = k + 1;
// 			j++;
// 			k++;	
			next[++j] = ++k;
		}
		else
		{
			k = next[k];
		}
	}
}

//O(m+n)
int KMP(const char *s, const char *p, int pos)
{
	assert(s != NULL && p != NULL);

	int lens = strlen(s);
	int lenp = strlen(p);

	if (lens < lenp)
	{
		return -1;
	}

	int i = pos;
	int j = 0;
	int *next = (int *)malloc(sizeof(int) * lenp);
	assert(next != NULL);

	GetNext(p, next);  //O(m)

	// O(n)
	while (i < lens && j < lenp)
	{
		if (j == -1 || s[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}

	free(next);

	if (j >= lenp)
	{
		return i - j;
	}

	return -1;
}

int main()
{
	char *s = "ababcabcdabcde";
	char *p = "abcd";

	printf("%d\n", KMP(s, p, 10));
	return 0;
}