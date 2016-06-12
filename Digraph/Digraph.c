#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Digraph.h""


SDigraph *createDigraph(int V)
{
	SDigraph *graph = calloc(1, sizeof(SDigraph));

	graph->array = malloc(sizeof(SAdjList)*V);
	graph->V = V;

	for (int i = 0; i < V; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void addEdge(SDigraph *graph, int source, int dest)
{
	if (source >= graph->V || dest >= graph->V)
		return;

	SAdjNode *nodeS = calloc(1, sizeof(SAdjNode));
	nodeS->next = graph->array[source].head;
	nodeS->vertex = dest;
	graph->array[source].head = nodeS;

}

SAdjNode *getAdjListHead(SDigraph *graph, int vertex)
{
	return graph->array[vertex].head;
}
#if 0
void main()
{
	SGraph *graph = createGraph(5);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 5);
	addEdge(graph, 3, 7);

	_getch();
}
#endif