//
//	쉘 정렬 요약
//	- 인접한 요소들을 비교하는 삽입정렬의 단점을 극복하기 위한 정렬 방법
//	1. 입력자료 형태에 상관없이 빠르다.( 10,000 이하의 자료)
//	2. 실제 프로그램에서 많이 사용한다 (추가적인 메모리사용도 안함)
//	3. 쉘정렬은 h간격의 잘 뽑아야한다.
//

#include <stdio.h>

void Show(int arr[],int arrlen)	
{
	int i;
	for (i = 0; i < arrlen; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("\n");
}

void Shell_sort(int arr[], int arrlen)
{
	int i, j, k, h, v;
	for (h = arrlen / 2; h > 0; h /= 2)
	{
		for (i = 0; i < h; i++)
		{
			for (j = i + h; j < arrlen; j += h)
			{
				v = arr[j];
				k = j;
				
				while (k > h - 1 && arr[k - h] > v)
				{
					arr[k] = arr[k - h];
					k -= h;
				}
				arr[k] = v;
			}
		}
	}
}

// 개선버전 ( 속도 향상이 존재 )
void Shell_sort_upgrade(int arr[], int arrlen)
{
	int i, j, k, h, v;

	// shell의 속도이점을 찾을려면 h간격을 잘 조정하는 것이다.
	for (h = 1; h < arrlen; h = 3 * h + 1) {}	// h의 효율적인 값을 찾음

	for (h /= 3; h > 0; h /= 3)
	{
		for (i = 0; i < h; i++)
		{
			for (j = i + h; j < arrlen; j += h)
			{
				v = arr[j];
				k = j;

				while (k > h - 1 && arr[k - h] > v)
				{
					arr[k] = arr[k - h];
					k -= h;
				}
				arr[k] = v;
			}
		}
	}
}

int main()
{
	int arrSort1[10] = { 1000,87,11,30,7,29,5,99,41,6 };
	int arrLen1 = sizeof(arrSort1) / sizeof(arrSort1[0]);

	int arrSort2[10] = { 1000,87,11,30,7,29,5,99,41,6 };
	int arrLen2 = sizeof(arrSort2) / sizeof(arrSort2[0]);

	printf("\n Shell Sort \n");
	Show(arrSort1, arrLen1);
	Shell_sort(arrSort1, arrLen1);
	Show(arrSort1, arrLen1);

	printf("\n---------------------------------------------------------\n");

	printf("\n Shell Sort Upgrade \n");
	Show(arrSort2, arrLen2);
	Shell_sort_upgrade(arrSort2, arrLen2);
	Show(arrSort2, arrLen2);

	return 0;
}