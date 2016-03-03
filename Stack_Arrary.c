#include <stdio.h>

#define MAXLENGTH 10

int stack[MAXLENGTH];
int top;

void init_stack()
{
	top = -1;
}

int push(int t)
{
	if (top >= MAXLENGTH - 1)	// 가득찼는지 확인
	{							// 0부터 시작하므로 -1 해줘야함
		printf("\n Stack overflow.");
		return -1;
	}

	stack[++top] = t;
	return t;	
}

int pop()
{
	if (top < 0)		// 비어있는 지확인
	{
		printf("\n Stack underflow.");
		return -1;
	}

	return stack[top--];
}

void printf_stack()
{
	int i;
	printf("\n Stack contents : Top -------> Bottom\n");
	for (i = top; i >= 0; i--)
	{
		printf("%-6d",stack[i]);
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

	printf("\n\n\n -------------------------------------------------");
	printf("\nPush 3");
	push(3);				// 오버플로 에러가 발생 배열의 최대크기를 넘어감
	printf("\n -------------------------------------------------\n\n");
	printf_stack();			

	printf("\nInitialize stack");
	init_stack();			// 스택 초기화
	printf_stack();

	printf("\n\n\n -------------------------------------------------");
	printf("\nNow stack is empty, pop");
	i = pop();				// 언더플로우 에러 , 스택초기화이후 pop 할게 아무것도 없으므로
	printf("\n -------------------------------------------------\n\n");
	printf_stack();

	printf("\n popping value is %d\n\n", i);

	return 0;
}