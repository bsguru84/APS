#ifndef QUEUE_H
#define QUEUE_H

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
	SNode *last;
}SQueue;

void Enqueue(SQueue *queue, int data);
int Dequeue(SQueue *queue);
bool isEmpty(SQueue *queue);

#endif