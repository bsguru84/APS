#ifndef EDGEWEIGHTEDGRAPH_H
#define EDGEWEIGHTEDGRAPH_H

typedef struct SDirectedEdge SDirectedEdge;
typedef struct SDirectedEdge{
	int source;
	int dest;
	float weight;
	SDirectedEdge *next;
}SDirectedEdge;

typedef struct SAdjList
{
	SDirectedEdge *head;
}SAdjList;

typedef struct SEdgeWeightedGraph{
	int V;
	SAdjList *array;
}SEdgeWeightedGraph;



SEdgeWeightedGraph *createGraph(int V);
void addEdge(SEdgeWeightedGraph *graph, int source, int dest);
SDirectedEdge *getAdjListHead(SEdgeWeightedGraph *graph, int vertex);

#endif