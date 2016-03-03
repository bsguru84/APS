#ifndef QUEUE_H
#define QUEUE_H

typedef struct data
{
	int index;
}Sdata;
typedef struct SNode
{
	void *data;
	SNode *next;
}SNode;

typedef struct
{
	SNode *first;
	SNode *last;
}SQueue;

void Enqueue(SQueue *queue, void *data);
void *Dequeue(SQueue *queue);
bool isEmpty(SQueue *queue);

#endif