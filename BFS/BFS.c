#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <Graph.h>
#include "Queue.h"


typedef struct SBFS
{
	bool *marked;
}SBFS;


//Queue version of DFS
void BFS(SBFS *dfs, SGraph *graph, int vertex)
{
	SQueue *queue = (SQueue*)calloc(1, sizeof(SQueue));
	int dequeData;
	SAdjNode *head;

	Enqueue(queue, vertex);

	while ((dequeData = Dequeue(queue)) != -1)
	{
		dfs->marked[dequeData] = true;
		printf("Visiting Node %d\n", dequeData);

		SAdjNode *iterNode = head = getAdjListHead(graph, dequeData);

		while (iterNode != NULL)
		{
			if (!dfs->marked[iterNode->vertex])
				Enqueue(queue, iterNode->vertex);

			iterNode = iterNode->next;
		}
	}


}
void main()
{
	SBFS *dfs = calloc(1, sizeof(SBFS));
	SGraph *graph = createGraph(8);

	dfs->marked = calloc(1, 8 * sizeof(bool));

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 5);
	addEdge(graph, 3, 7);
	//addEdge(graph, 4, 6);

	//DFS(dfs,graph, 7);

	BFS(dfs, graph, 0);

	_getch();
}