#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define swap(x, y, T) do { T SWAP = x; x = y; y = SWAP; } while (0)
void quickSort(int left, int right, int* nums, int N);
int quickSortUtil(int left, int right, int* nums, int N);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int N, int* returnSize){
	int* res = (int*) malloc(sizeof(int)*N);
	memcpy(res, nums, N*sizeof(int));
	*returnSize = N;
	quickSort(0, N-1, res, N);
	return res;
}

void quickSort(int left, int right, int* nums, int N){
	if (left < right){
		int p_idx = quickSortUtil(left, right, nums, N);
		quickSort(left, p_idx-1, nums, N); // left half
		quickSort(p_idx+1, right, nums, N); // right half, ignore middle
	}
}

int quickSortUtil(int left, int right, int* nums, int N){
	// parition the array. 
	// This means that all elemeents smaller than the pivot should be left of it and greater than it should be on the right
	int pivot = nums[right];
	int i = left-1;
	for (int j = left; j < right; j++)
		if (nums[j] < pivot){
			i++; 
			swap(nums[i], nums[j], int);
		}
	swap(nums[i+1], nums[right], int);
	return i+1;
}

int main(){
	int arr[] = {5,3,2,1}; int N = 4;
	int rsz;
	int* res = sortArray(arr, N, &rsz);
	for (int i = 0; i < N; i++)
		printf("%i ", res[i]);
	printf("\n");
}
