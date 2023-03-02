#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


typedef struct Graph {
	int **adj;
	int *neighbor_count;
	int V, E;
	size_t mem_size;
} Graph;

Graph* initGraph(){
	Graph* new_graph = (Graph*) malloc(sizeof(Graph));	
	new_graph->mem_size = 10;
	new_graph->V = new_graph->E = 0;	
	new_graph->adj = (int**) malloc(sizeof(int*) * new_graph->mem_size);
	new_graph->neighbor_count = (int*) malloc(sizeof(int) * new_graph->mem_size);
	return new_graph;
}

void addEdge(int src, int dest, Graph* graph){
	if (src >= graph->mem_size){
		graph->mem_size += 10;
		graph->adj = (int**) realloc(graph->adj, sizeof(int*) * graph->mem_size);
	}

}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, 
				int* prerequisitesColSize, int* returnSize){
	int* res = NULL;
	int indegree[numCourses];
	memset(indegree, 0, numCourses);
	int visited[numCourses];
	memset(visited, 0, numCourses);
	for (int i = 0; i < prerequisitesSize; i++){
		int dest = prerequisites[i][0], src = prerequisites[i][1];
		indegree[dest]++;
	}


	return res;
}

int main(){
	Graph* g = initGraph();

}
