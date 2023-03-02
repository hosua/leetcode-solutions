#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
       	return binarySearch(target, 0, nums.size()-1, nums);
    }

	int binarySearch(int target, int left, int right, vector<int> nums){
		// cout << left << " " << right << endl;
		int mid = (left + right)/2;
		if (left <= right){
			if (target == nums[mid]){
				return mid;
			} else if (target < nums[mid]){
				return binarySearch(target, left, mid-1, nums);
			} else { // target > nums[mid]
				return binarySearch(target, mid+1, right, nums);
			}
		}
		return -1;
	}
};
int main(){
	vector<int> nums = {-1,0,3,5,9,12};
	// vector<int> nums = {5};
	Solution sol;
	// cout << sol.search(nums, -2);
	// for (int num : nums){
	// 	cout << sol.search(nums, num);
	// }
}
