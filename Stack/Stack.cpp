#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Stack.h"


Sdata *pack(int index)
{
	Sdata* data = (Sdata*)malloc(sizeof(Sdata));
	data->index = index;
	return data;
}

int unpack(Sdata *data)
{
	if (data == NULL)
		return -1;

	int ret = data->index;
	free(data);
	return ret;
}

bool isEmpty(SStack *stack)
{
	return stack->first == NULL;
}

void Push(SStack *stack, int data)
{
	SNode *node = (SNode*)malloc(sizeof(SNode));
	SNode *oldfirst = stack->first;

	node->data = data;
	node->next = oldfirst;

	stack->first = node;
}

int Pop(SStack *stack)
{
	if (isEmpty(stack))
		return NULL;

	int data = stack->first->data;
	stack->first = stack->first->next;

	return data;
}

void main()
{
	SStack *stack = (SStack*)calloc(1, sizeof(SStack));

	printf("Popped Data : %d\n", Pop(stack));
	printf("Popped Data : %d\n", Pop(stack));
	printf("Popped Data : %d\n", Pop(stack));

	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	Push(stack, 5);

	printf("Popped Data : %d\n", Pop(stack));
	printf("Popped Data : %d\n", Pop(stack));
	printf("Popped Data : %d\n", Pop(stack));
	printf("Popped Data : %d\n", Pop(stack));
	printf("Popped Data : %d\n", Pop(stack));

	printf("Popped Data : %d\n", unpack((Sdata*)Pop(stack)));

	_getch();

}
