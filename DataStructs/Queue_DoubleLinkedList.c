//			
//			Duble Linked List Queue (����ũ�� ����Ʈ ť)
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _dnode
{
	int key;
	struct _dnode * prev;
	struct _dnode * next;
}dnode;

dnode *head, *tail;

void init_queue()
{
	head = (dnode*)malloc(sizeof(dnode));
	tail = (dnode*)malloc(sizeof(dnode));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void clear_queue()
{
	dnode* t;
	dnode* s;
	t = head->next;
	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}
	head->next = tail;
	tail->prev = head;
}

int put(int k)
{
	dnode* t;
	if ((t = (dnode*)malloc(sizeof(dnode))) == NULL)
	{
		printf("\n Out of Memory.");
		return -1;
	}
	t->key = k;
	tail->prev->next = t;
	t->prev = tail->prev;
	tail->prev = t;
	t->next = tail;
	return k;
}

int get()
{
	dnode* t;
	int i;
	t = head->next;		
	if (t == tail)		// t = head->next�̹Ƿ� head������ tail�̸� ������ֳ� Ȯ��
	{
		printf("\n Queue underflow.");
		return -1;
	}

	i = t->key;
	head->next = t->next;
	t->next->prev = head;
	free(t);
	return i;
}

void printf_queue()
{
	dnode* t;
	t = head->next;
	printf("\n Queue contents : Front -----------------> Rear\n");
	while (t != tail)
	{
		printf("%-6d", t->key);
		t = t->next;
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
	put(3);					// ���Ḯ��Ʈ�� ����ҽ� �����Ҵ��̹Ƿ� overflow�߻� X
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