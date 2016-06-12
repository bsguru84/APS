#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "EdgeWeightedGraph.h"


SEdgeWeightedGraph *createEdgeWeightedGraph(int V)
{
	SEdgeWeightedGraph *graph = calloc(1, sizeof(SEdgeWeightedGraph));

	graph->array = malloc(sizeof(SAdjList)*V);
	graph->V = V;

	for (int i = 0; i < V; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

void addEdge(SEdgeWeightedGraph *graph , int source , int dest , float weight)
{	
	SDirectedEdge *edge = calloc(1, sizeof(SDirectedEdge));
	edge->source = source;
	edge->next = graph->array[source].head;
	edge->dest = dest;
	edge->weight = weight;
}

SDirectedEdge *getAdjListHead(SEdgeWeightedGraph *graph, int vertex)
{
	return graph->array[vertex].head;
}
#if 0
void main()
{
	SEdgeWeightedGraph *graph = createEdgeWeightedGraph(5);

	addEdge(graph, 0, 1,10);
	addEdge(graph, 0, 4);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 6);
	addEdge(graph, 2, 5);
	addEdge(graph, 3, 7);

	_getch();
}
#endif