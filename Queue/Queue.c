#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Queue.h"


Sdata *pack(int index)
{
	Sdata* data = (Sdata*)malloc(sizeof(Sdata));
	data->index = index;
	return data;
}

int unpack(Sdata *data)
{
	int ret = data->index;
	free(data);
	return ret;
}
bool isEmpty(SQueue *queue)
{
	return queue->first == NULL;
}
void Enqueue(SQueue *queue,int data)
{
	SNode* last = (SNode*)malloc(sizeof(SNode));
	SNode *oldlast = queue->last;

	last->data = data;
	last->next = NULL;	

	if (isEmpty(queue))
	{
		queue->first = queue->last = last;
	}
	else
	{
		oldlast->next = last;
		queue->last = last;
	}

	
}

int Dequeue(SQueue *queue)
{
	int data = NULL;
	SNode *first = NULL;
	if (isEmpty(queue))
		return -1;

	first = queue->first;
	data = first->data;

	queue->first = first->next;
	if (isEmpty(queue))
		queue->last = NULL;

	return data;
}

#if 0
void main()
{
	SQueue *queue = (SQueue*)calloc(1,sizeof(SQueue));

	Enqueue(queue, 1);
	Enqueue(queue, 3);
	Enqueue(queue, 4);
	Enqueue(queue, 5);
	Enqueue(queue, 8);

	printf("Dequede Data : %d\n", Dequeue(queue));
	printf("Dequede Data : %d\n", Dequeue(queue));
	printf("Dequede Data : %d\n", Dequeue(queue));
	printf("Dequede Data : %d\n", Dequeue(queue));
	printf("Dequede Data : %d\n", Dequeue(queue));
	printf("Dequede Data : %d\n", Dequeue(queue));

	_getch();

}
#endif