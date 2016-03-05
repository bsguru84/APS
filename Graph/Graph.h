#ifndef GRAPH_H
#define GRAPH_H

typedef struct SAdjNode SAdjNode;
typedef struct SAdjNode
{
	int vertex;
	SAdjNode *next;
}SAdjNode;

typedef struct SAdjList
{
	SAdjNode *head;
}SAdjList;

typedef struct SGraph{
	int V;
	SAdjList *array;
}SGraph;

SGraph *createGraph(int V);
void addEdge(SGraph *graph, int source, int dest);
SAdjNode *getAdjListHead(SGraph *graph, int vertex);
#endif