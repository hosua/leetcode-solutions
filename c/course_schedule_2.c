#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, 
				int* prerequisitesColSize, int* returnSize){
	int* res = NULL;
	int indegree[numCourses];
	memset(indegree, 0, numCourses);
	for (int i = 0; i < prerequisitesSize; i++){
		int dest = prerequisites[i][0], src = prerequisites[i][1];
	}
	return res;
}

int main(){


}
