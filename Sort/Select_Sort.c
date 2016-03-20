//
//	선택 정렬의 요약
//	- 가장 단순한 정렬 알고리즘(단순비교 하여 교환끝)
//	1. 배열의 개수가 늘어날수록 느려지므로 100개이하에서는 만족
//	2. 비교가 많고 교환이 적다.
//	3. 역순, 이중루프등.. 속도가 고름

#include <stdio.h>

void Show(int arrLen, int arr[])	// 배열을 매개변수로 넘길때 arr[] == *arr 같음
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void select_sort(int arrLen, int* arr)
{
	int i, j;
	int temp;
	int min;
	for (i = 0; i < arrLen-1; i++)
	{
		j = 1;
		min = arr[i];
		for (j = i+j; j < arrLen; j++)
		{
			if (min > arr[j])	// 되도록 배열vs배열 비교하지말것 느림
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int arr[10] = { 1000,87,11,30,7,29,5,99,41,6 };
	int arrLen = sizeof(arr)/sizeof(arr[0]);	

	Show(arrLen,arr);
	select_sort(arrLen,arr);
	Show(arrLen,arr);

	return 0;
}

