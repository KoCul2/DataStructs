//
//	버블 정렬 요약
//	- 인접한 배열의 요소를 비교 교환하는 방법의 정렬
//	1. 실행시간이 굉장히 느리다.
//	2. 역순, 이중루프등.. 상황에따라서 차이가 안남 고르게 느려서 사용잘 안함.
//

#include <stdio.h>

void Show(int arr[],int arrlen)
{
	int i;
	for (i = 0; i < arrlen; i++)
	{
		printf(" %d, ", arr[i]);
	}
	printf("\n");
}

void Bubble_sort(int arr[],int arrlen)
{								// sortBool은 정렬이 되어있는지 아닌지 확인
	int i, j, t, sortBool;		// 완전히 정렬되어있으면 1의값 아니면 0

	for (i = 0; i < arrlen - 1; i++)
	{
		sortBool = 1;			// 정렬이 되어있다고 가정
		for (j = 1; j < arrlen; j++)
		{
			if (arr[j - 1] > arr[j])	// 배열과 배열 비교시 느림
			{				
				t = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = t;
				sortBool = 0;	// 정렬이 되어있지 않음
			}
		}

		if (sortBool == 1)		// 정렬이 되어있을시 끝냄
		{
			break;
		}
	}
}

int main()
{
	int arrSort[10] = { 1000,87,11,30,7,29,5,99,41,6 };
	int arrLen = sizeof(arrSort) / sizeof(arrSort[0]);

	Show(arrSort, arrLen);
	Bubble_sort(arrSort, arrLen);
	Show(arrSort, arrLen);

	return 0;
}