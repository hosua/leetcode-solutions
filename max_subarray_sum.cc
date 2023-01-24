#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       	int max_sum = nums[0]; 
		int curr_sum = max_sum;
		for (int i = 1; i < nums.size(); i++){
			max_sum = max(max_sum, curr_sum = max(nums[i], curr_sum+nums[i]));
		}
		return max_sum;
    }
};

int main(){
    Solution sol;
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4}; // Output: 6
	int res = sol.maxSubArray(nums);
	cout << res << "\n";
}
