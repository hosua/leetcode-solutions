#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int searchInsertUtil(int target, int left, int right, int* nums, int n);

int searchInsert(int* nums, int n, int target){
	return searchInsertUtil(target, 0, n-1, nums, n);	
}

int searchInsertUtil(int target, int left, int right, int* nums, int n){
	int mid = (left+right)/2;

	if (left > right){
		return (target < nums[mid]) ? mid : mid+1;
	} else if (nums[mid] == target)
		return mid;
	else if (nums[mid] < target)
		return searchInsertUtil(target, mid+1, right, nums, n);
	else 
		return searchInsertUtil(target, left, mid-1, nums, n);
}

void test(){
	int arr[] = {1,3,5,6};
	int n = 4;

	int tests[] = {5,2,7,0};
	int expected[] = {2,1,4,0};
	int t = 4;

	for (int i = 0; i < 4; i++){
		printf("Testing: in: %i\tout: %i\n", tests[i], expected[i]);
		assert(searchInsert(arr, n, tests[i]) == expected[i]);
	}
	// int target = 2; // 1
	int target = 0; // 0
	int res = searchInsert(arr, n, target);
	printf("res: %i\n", res);
}

int main(){
	test();
}
