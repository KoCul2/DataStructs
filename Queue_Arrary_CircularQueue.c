//			
//			Circle Queue Arrary (���� �迭 ť)
//

#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 10
int queue[MAXLENGTH];
int front, rear;

void init_queue()
{
	front = rear = 0;
}

void clear_queue()
{
	front = rear;
}

int put(int k)
{
	if ((rear + 1) % MAXLENGTH == front)	// �޸𸮰� ���̻�ȸ���������
	{
		printf("\n Queue overflow");
		return -1;
	}
	queue[rear] = k;
	rear = ++rear%MAXLENGTH;
	return k;
}

int get()
{
	int i;
	if (front == rear)
	{
		printf("\n Queue underflow");
		return -1;
	}
	i = queue[front];
	front = ++front%MAXLENGTH;
	return i;
}

void printf_queue()
{
	int i;
	printf("\n Queue contents : Front ---------> Rear\n");
	for (i = front; i != rear; i = ++i%MAXLENGTH)
	{
		printf("%-6d", queue[i]);
	}
}

int main()
{
	int i;
	init_queue();

	printf("\nPut 5, 4, 7, 8, 2, 1");
	put(5);
	put(4);
	put(7);
	put(8);
	put(2);
	put(1);
	printf_queue();

	printf("nGet");
	i = get();
	printf_queue();
	printf("\n getting value is %d", i);

	printf("\nPut 3, 2, 5, 7");
	put(3);
	put(2);
	put(5);
	put(7);
	printf_queue();

	printf("\n\n\n -------------------------------------------------");
	printf("\nNow queue is full, put 3");
	put(3);					// �迭�� ũ��� 10������ ����ť���� ������ �ϳ��־���ϹǷ� 9���� ����.
							// �׷��� 10������ overflow�߻�
	printf("\n -------------------------------------------------\n\n");

	printf_queue();

	printf("\nInitialize queue");
	clear_queue();
	printf_queue();

	printf("\nNow queue is empty, get");
	i = get();
	printf_queue();
	printf("\n getting value is %d\n\n", i);

	return 0;
}