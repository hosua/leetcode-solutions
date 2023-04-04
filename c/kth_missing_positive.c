#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int findKthPositive(int* arr, int n, int k);
int binarySearch(int* arr, int k, int left, int right);

int findKthPositive(int* arr, int n, int k){
	return k+binarySearch(arr, k, 0, n-1);		
}

int binarySearch(int* arr, int k, int left, int right){
	int mid = left + (right-left)/2;
	if (left > right)
		return left;
	else if (arr[mid] - (mid+1) < k)
		return binarySearch(arr, k, mid+1, right);
	else
		return binarySearch(arr, k, left, mid-1);
}


int main(){
	// int arr[] = {2,3,4,7,11}; int k = 5; 
	int arr[] = {1,2,3,4}; int k = 2; 
	int n = sizeof(arr)/sizeof(*arr);
	int res = findKthPositive(arr, n, k);
	printf("res: %i\n", res);
}
