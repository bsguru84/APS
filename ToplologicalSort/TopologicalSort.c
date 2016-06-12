#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <Digraph.h>
#include "Stack.h"

typedef struct SDFS
{
	bool *marked;	
}SDFS;
//Recursive version of DFS
void DFSRec(SDFS *dfs, SDigraph *graph, int vertex)
{
	dfs->marked[vertex] = true;

	//printf("Visiting Node %d\n", vertex);

	SAdjNode *head = getAdjListHead(graph, vertex);
	SAdjNode *iterNode = head;

	while (iterNode != NULL)
	{
		if (!dfs->marked[iterNode->vertex])
			DFSRec(dfs, graph, iterNode->vertex);

		iterNode = iterNode->next;
	}

	printf("Node : %d\n", vertex);
}

//Stakc version of DFS
void DFSStack(SDFS *dfs, SDigraph *graph, int vertex)
{
	SStack *stack = (SStack*)calloc(1, sizeof(SStack));
	int popData;
	SAdjNode *head;

	Push(stack, vertex);	

	while ((popData = Pop(stack)) != -1)
	{
		printf("Visiting Node %d\n", popData);

		SAdjNode *iterNode = head = getAdjListHead(graph, popData);

		while (iterNode != NULL)
		{
			if (!dfs->marked[iterNode->vertex])
			{
				dfs->marked[iterNode->vertex] = true;				
				Push(stack, iterNode->vertex);
			}
			iterNode = iterNode->next;
		}
	}


}

#define VERTEX 5
#if 0
void main()
{
	SDFS *dfs = calloc(1, sizeof(SDFS));
	SDigraph *graph = createDigraph(VERTEX);

	dfs->marked = calloc(1, VERTEX*sizeof(bool));	

	addEdge(graph, 0, 1);
	addEdge(graph, 2, 1);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);
	//addEdge(graph, 2, 3);
	//addEdge(graph, 2, 4);
	//addEdge(graph, 4, 6);
	//addEdge(graph, 4, 5);
	//addEdge(graph, 7, 5);
	//addEdge(graph, 4, 7);

	//DFS(dfs,graph, 7);

	for (int i = 0; i < graph->V; i++)
	{
		if (!dfs->marked[i])
			DFSRec(dfs, graph, i);
	}

	_getch();
}
#endif