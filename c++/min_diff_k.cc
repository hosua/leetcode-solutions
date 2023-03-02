#include <bits/stdc++.h>
using namespace std;

class Solution {
	// ???
	public:
		int minimumDifference(vector<int>& nums, int k) {
			if (nums.size() == 1)
				return 0;
			int left = 0, right = nums.size()-1;
			int direction = 1;
			int min_diff = INT_MAX;
			while (left < right){
				int delta = abs(nums[left] - nums[right]);
				if (delta < min_diff) 
					min_diff = delta;
				(direction > 0) ? left++ : right--;
				direction *= -1;
			}
			return min_diff;
		}
};

int main(){
	Solution sol;
	// vector<int> nums = {9,4,1,7}; int k = 2;
	vector<int> nums = {87063,61094,44530,21297,95857,93551,9918}; int k = 6;
	cout << sol.minimumDifference(nums, k);
}
