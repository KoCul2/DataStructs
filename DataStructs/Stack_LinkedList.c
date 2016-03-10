//
//						Stack Linkded List (연결리스트 스택)
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int key;
	struct _node* next;
}node;

node *head, *tail;

void init_stack()
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->next = tail;
	tail->next = tail;
}

void clear_stack()
{
	node *t, *s;
	t = head->next;

	while (t != tail)
	{
		s = t;
		t = t->next;
		free(s);
	}

	head->next = tail;
}

int push(int k)
{
	node *t;

	if ((t = (node*)malloc(sizeof(node))) == NULL)
	{
		printf("\n Out of Memory...");
		return -1;
	}

	t->key = k;
	t->next = head->next;
	head->next = t;
	return k;
}

int pop()
{
	node *t;
	int i;

	if (head->next == tail)
	{
		printf("\n Stack underflow.");
		return -1;
	}

	t = head->next;
	i = t->key;
	head->next = t->next;
	free(t);
	return i;
}

// 출력
void printf_stack()
{
	node *t;
	t = head->next;

	printf("\n Stack contents : Top -------> Bottom\n");

	while (t != tail)
	{
		printf("%-6d", t->key);
		t = t->next;
	}
}

int main()
{
	int i;
	init_stack();

	printf("\nPush 5, 4, 7, 8, 2, 1");
	push(5);
	push(4);
	push(7);
	push(8);
	push(2);
	push(1);
	printf_stack();

	printf("\nPop");
	i = pop();
	printf_stack();
	printf("\n popping value is %d", i);

	printf("\nPush 3, 2, 5, 7, 2");
	push(3);
	push(2);
	push(5);
	push(7);
	push(2);
	printf_stack();

	printf("\nPush 3");
	push(3);				// 동적할당시에는 메모리제한이 배열보다 자유롭다
	printf_stack();			// overflow발생 안함

	printf("\nInitialize stack");
	clear_stack();
	printf_stack();

	printf("\nNow stack is empty, pop");
	i = pop();
	printf_stack();

	printf("\n popping value is %d\n\n", i);

	return 0;
}