//
//	�� ���� ���
//	- ������ ��ҵ��� ���ϴ� ���������� ������ �غ��ϱ� ���� ���� ���
//	1. �Է��ڷ� ���¿� ������� ������.( 10,000 ������ �ڷ�)
//	2. ���� ���α׷����� ���� ����Ѵ� (�߰����� �޸𸮻�뵵 ����)
//	3. �������� h������ �� �̾ƾ��Ѵ�.
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

// �������� ( �ӵ� ����� ���� )
void Shell_sort_upgrade(int arr[], int arrlen)
{
	int i, j, k, h, v;

	// shell�� �ӵ������� ã������ h������ �� �����ϴ� ���̴�.
	for (h = 1; h < arrlen; h = 3 * h + 1) {}	// h�� ȿ������ ���� ã��

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