//
//	���� ���� ���
//	- ������ �迭�� ��Ҹ� �� ��ȯ�ϴ� ����� ����
//	1. ����ð��� ������ ������.
//	2. ����, ���߷�����.. ��Ȳ������ ���̰� �ȳ� ���� ������ ����� ����.
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
{								// sortBool�� ������ �Ǿ��ִ��� �ƴ��� Ȯ��
	int i, j, t, sortBool;		// ������ ���ĵǾ������� 1�ǰ� �ƴϸ� 0

	for (i = 0; i < arrlen - 1; i++)
	{
		sortBool = 1;			// ������ �Ǿ��ִٰ� ����
		for (j = 1; j < arrlen; j++)
		{
			if (arr[j - 1] > arr[j])	// �迭�� �迭 �񱳽� ����
			{				
				t = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = t;
				sortBool = 0;	// ������ �Ǿ����� ����
			}
		}

		if (sortBool == 1)		// ������ �Ǿ������� ����
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