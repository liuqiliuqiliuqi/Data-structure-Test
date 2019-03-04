#include<stdio.h>

void Swap(int *p, int *q)
{
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void Show(int *arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d   ", arr[i]);
	}

}

void bubbleSort(int *arr,int len)
{
	int i, j ;
	for (i = 0; i < len ; i++)
	{
		for (j = 0; j < len  - i-1; j++)
		{
			if (arr[j]>arr[j+1])
			{
				Swap(&arr[j], &arr[j + 1]);
			}
		}
	}

}

void SelectSort(int *arr, int len)
{
	int min = 0;
	int i, j;
	for (i = 0; i < len - 1; i++)
	{
		min = i;
		for (j = i + 1; j < len - 1; j++)
		{
			if (arr[j]<arr[min])
			{
				min = j;
			}
		}
		Swap(&arr[i], &arr[min]);
	}
}

void InsertSort(int *arr, int len)
{
	int i,j,tmp;
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0; --j)
		{
			if (arr[j ]>tmp)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j + 1] = tmp;
	}
}

void ShellSort(int *arr, int len)
{
	int i, j, width;
	for (width = len / 2; width > 0; width /= 2)
	{
		for (i = width; i < len; i++)
		{
			for (j = i - width; j >= 0 && arr[j]>arr[j+width]; j -= width)
			{
				Swap(&arr[j], &arr[j + width]);

			}
		}
	}

}

void QuickSort(int *arr, int left,int right)
{
	int i=left, j=right;
	int flag = left;
	int tmp = arr[i];
	while (i != j)
	{
		
		for (;j >= 0 && i!=j; j--)
		{
			if (arr[j] < tmp)
			{
				arr[flag] = arr[j];
				flag = j;
				break;
			}
		}
		for (; i <= right && i!=j ; i++)
		{
			if (arr[i]>tmp)
			{
				arr[j] = arr[i];
				flag = i;
				break;
			}
		}
		arr[i] = tmp;
		
		
	}

	if (left<flag)
		QuickSort(arr, left, flag - 1);
	
	if (right>flag)
		QuickSort(arr, flag +1, right);
	
	
}

//
//
//void  HeapSort()
//{
//	CreateHeap(arr, len);
//	int end = len - 1;
//	for (int i = 0; i < len; ++i)
//	{
//		Swap(&arr[0], arr[len - 1 - i]);
//		Adjust(arr, len - 1 - i, 0);
//	}
//
//}

int main()
{
	int arr[] = { 22, 12, 4, 56, 32, 13, 44, 21, 66,1 };
	int len = sizeof(arr)/sizeof(arr[0]);

	/*bubbleSort(arr, len);
	Show(arr, len);

	SelectSort(arr, len);
	printf("\n");
	Show(arr, len);

	InsertSort(arr, len);
	printf("\n");
	Show(arr, len);*/

	ShellSort(arr, len);
	printf("\n");
	Show(arr, len);

	QuickSort(arr, 0,len-1);
		printf("\n");
	Show(arr, len);
	
	return 0;
}