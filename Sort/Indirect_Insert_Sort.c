//
//	간접 정렬 요약
//	- 원본은 그대로 놔두고 사본을 생성해서 사용, 삽입정렬사용
//	1. 데이터베이스쪽에서 많이 사용함
//

#include <stdio.h>
#include <stdlib.h>

void Show(int arrLen, int arr[])
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		printf(" %d, ", arr[i]);
	}
	printf("\n");	
}

void Change_indirect_insert_sort(int index[], int arr[],int arrLen)
{
	int i, j;
	int* temp = (int*)malloc(sizeof(arr[0])*arrLen);

	for (i = 0; i < arrLen; i++)
	{
		for (j = 0; j < arrLen; j++)
		{
			if (index[i] == j)
			{
				temp[i] = arr[j];
				break;
			}
		}
	}

	for (i = 0; i < arrLen; i++)
	{
		arr[i] = temp[i];
	}

	free(temp);

	Show(arrLen, arr);
}

void Init_indirect_insert_sort(int index[], int arrLen)
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		index[i] = i;
	}
}

void Indirect_insert_sort(int arr[], int index[], int arrLen)
{
	int i, j, t;

	for (i = 1; i < arrLen; i++)
	{
		t = index[i];
		j = i;

		while (j > 0)
		{
			int a = index[j - 1];

			if (arr[a] > arr[t])
			{
				index[j] = index[j - 1];
				j--;
			}
			else
			{
				break;
			}
		}
		index[j] = t;
	}
}

int main()
{
	int arr[10] = { 1000,87,11,30,7,29,5,99,41,6 };
	int index_Arr[10];
	int arrLen = sizeof(arr) / sizeof(arr[0]);

	Init_indirect_insert_sort(index_Arr, arrLen);

	printf("\n  IndexArr Show \n");

	Show(arrLen, index_Arr);
	Indirect_insert_sort(arr, index_Arr, arrLen);
	Show(arrLen, index_Arr);	// Index 사본배열만 바뀌어있음

	printf("\n------------------------------------------------------\n");
	printf("\n  Arr Show \n");	// 원본은 안바뀌어있음

	Show(arrLen, arr);

	printf("\n Arr Change Show \n"); // Index사본배열로 원본배열 교체
	Change_indirect_insert_sort(index_Arr, arr, arrLen);
	
	return 0;
}