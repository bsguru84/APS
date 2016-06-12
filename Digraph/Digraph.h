#ifndef DIGRAPH_H
#define DIGRAPH_H

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
}SDigraph;

SDigraph *createGraph(int V);
void addEdge(SDigraph *graph, int source, int dest);
SAdjNode *getAdjListHead(SDigraph *graph, int vertex);
#endif