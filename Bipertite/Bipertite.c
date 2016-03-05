#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <Graph.h>
#include "Stack.h"

typedef enum{
	RED = 0,
	BLACK
}EColor;

typedef struct SDFS
{
	bool *marked;
	EColor *color;
	bool bipertite;
}SDFS;
//Recursive version of DFS
void DFSRec(SDFS *dfs,SGraph *graph, int vertex)
{
	dfs->marked[vertex] = true;

	printf("Visiting Node %d\n", vertex);

	SAdjNode *head = getAdjListHead(graph,vertex);
	SAdjNode *iterNode = head;

	while (iterNode != NULL)
	{
		if (!dfs->marked[iterNode->vertex])
			DFSRec(dfs, graph, iterNode->vertex);
		
		iterNode = iterNode->next;
	}
}

//Stakc version of DFS
void DFSStack(SDFS *dfs, SGraph *graph, int vertex)
{
	SStack *stack = (SStack*)calloc(1, sizeof(SStack));
	int popData;
	SAdjNode *head;

	Push(stack, vertex);
	dfs->color[vertex] = RED;

	while ((popData = Pop(stack)) != -1)
	{		
		printf("Visiting Node %d\n", popData);

		SAdjNode *iterNode = head = getAdjListHead(graph, popData);

		while (iterNode != NULL)
		{
			if (!dfs->marked[iterNode->vertex])
			{
				dfs->marked[iterNode->vertex] = true;
				dfs->color[iterNode->vertex] = !dfs->color[popData];
				Push(stack, iterNode->vertex);
			}
			else
			{
				if (dfs->color[iterNode->vertex] == dfs->color[popData])
					dfs->bipertite = false;
			}

			iterNode = iterNode->next;
		}
	}


}

#define VERTEX 8

void main()
{
	SDFS *dfs = calloc(1, sizeof(SDFS));
	SGraph *graph = createGraph(VERTEX);

	dfs->marked = calloc(1, VERTEX*sizeof(bool));
	dfs->color = calloc(1, VERTEX * sizeof(EColor));
	dfs->bipertite = true;

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 0, 6);
	addEdge(graph, 0, 5);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 4, 6);
	addEdge(graph, 4, 5);
	addEdge(graph, 7, 5);
	addEdge(graph, 4, 7);

	//DFS(dfs,graph, 7);

	DFSStack(dfs, graph, 0);

	if (dfs->bipertite)
		printf("Graph is bipertite!");
	else
		printf("Graph is not bipertite!");

	_getch();
}