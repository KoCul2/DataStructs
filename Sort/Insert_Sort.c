//
//	삽입 정렬의 요약
//	- 기존의 정렬에서 데이터를 하나씩 적절한 위치에 삽입해가는 정렬방법이다.
//	1. 비교가 적고, 교환이 많다.
//	2. 입력 자료에 따라 속도차이가 많이난다 (작은 크기에서 굿)
//	3. 큰 데이터는 간접 정렬기법을 이용해야한다.
//	4. 이미정렬된 배열이나 대충 정렬된 배열에서 속도가 빠름
//

#include <stdio.h>

void Show(int arrLen,int arr[])
{
	int i;
	for (i = 0; i < arrLen; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void insert_sort(int arrLen, int* arr)
{
	int i,j,t;
	for (i = 1; i < arrLen; i++)
	{
		t = arr[i];
		j = i;
		while (arr[j - 1]>t && j > 0)	// t를쓰는이유?
		{								// => arr[j]로 찾는것보다 속도이점
			arr[j] = arr[j - 1];		
			j--;
		}
		arr[j] = t;
	}
}

int main()
{
	int arr[10] = { 1000,87,11,30,7,29,5,99,41,6 };
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	
	Show(arrLen, arr);
	insert_sort(arrLen, arr);
	Show(arrLen, arr);

	return 0;
}