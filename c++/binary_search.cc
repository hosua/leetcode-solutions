#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
 		function <int(int,int)> searchUtil;       
		searchUtil = [&](int left, int right) -> int {
			int mid = left+(right-left)/2;
			if (right < left)
				return -1;
			else if (target == nums[mid])
				return mid;
			else if (target < nums[mid])
				return searchUtil(left, mid-1);
			else
				return searchUtil(mid+1, right);
		};
		return searchUtil(0, nums.size()-1);
    }
};

int main(){
    Solution sol;
	vector<int> nums = {-1,0,3,5,9,12}; int target = 9;
	int res = sol.search(nums, target);
	cout << res << "\n";
}
