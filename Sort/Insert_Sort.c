//
//	���� ������ ���
//	- ������ ���Ŀ��� �����͸� �ϳ��� ������ ��ġ�� �����ذ��� ���Ĺ���̴�.
//	1. �񱳰� ����, ��ȯ�� ����.
//	2. �Է� �ڷῡ ���� �ӵ����̰� ���̳��� (���� ũ�⿡�� ��)
//	3. ū �����ʹ� ���� ���ı���� �̿��ؾ��Ѵ�.
//	4. �̹����ĵ� �迭�̳� ���� ���ĵ� �迭���� �ӵ��� ����
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
		while (arr[j - 1]>t && j > 0)	// t����������?
		{								// => arr[j]�� ã�°ͺ��� �ӵ�����
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