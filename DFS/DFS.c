#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <Graph.h>
#include "Stack.h""


typedef struct SDFS
{
	bool *marked;
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

	while ((popData = Pop(stack)) != -1)
	{
		dfs->marked[popData] = true;
		printf("Visiting Node %d\n", popData);

		SAdjNode *iterNode = head = getAdjListHead(graph, popData);

		while (iterNode != NULL)
		{
			if (!dfs->marked[iterNode->vertex])
				Push(stack, iterNode->vertex);

			iterNode = iterNode->next;
		}
	}


}
void main()
{
	SDFS *dfs = calloc(1, sizeof(SDFS));
	SGraph *graph = createGraph(8);

	dfs->marked = calloc(1, 8*sizeof(bool));

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 5);
	addEdge(graph, 3, 7);
	//addEdge(graph, 4, 6);

	//DFS(dfs,graph, 7);

	DFSStack(dfs, graph, 7);

	_getch();
}