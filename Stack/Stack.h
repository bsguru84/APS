#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
typedef struct data
{
	int index;
}Sdata;
typedef struct SNode SNode;
typedef struct SNode
{
	int data;
	SNode *next;
}SNode;

typedef struct
{
	SNode *first;	
}SStack;

void Push(SStack *stack, int data);
int Pop(SStack *stack);
bool isEmpty(SStack *stack);

#endif