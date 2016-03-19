//
//	���� ������ ���
//	- ���� �ܼ��� ���� �˰���(�ܼ��� �Ͽ� ��ȯ��)
//	1. �迭�� ������ �þ���� �������Ƿ� 100�����Ͽ����� ����
//	2. �񱳰� ���� ��ȯ�� ����.
//	

#include <stdio.h>

void Show(int arrLen, int arr[])	// �迭�� �Ű������� �ѱ涧 arr[] == *arr ����
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
	for (i = 0; i < arrLen-1; i++)
	{
		j = 1;
		for (j = i+j; j < arrLen; j++)
		{
			if (arr[i] > arr[j])	//��������
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

