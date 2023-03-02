#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	int maxSubarraySumCircular(vector<int>& nums) {
       	int max_sum = nums[0]; 
		int min_sum = nums[0];
		int sum = nums[0];
		int curr_max = max_sum;
		int curr_min = min_sum;
		for (int i = 1; i < nums.size(); i++){
			sum += nums[i];
			max_sum = max(max_sum, curr_max = max(nums[i], curr_max+nums[i]));
			min_sum = min(min_sum, curr_min = min(nums[i], curr_min+nums[i]));
		}
		return (max_sum > 0) ? max(max_sum, sum-min_sum) : max_sum;
    }
};

void test(Solution sol){
	vector<vector<int>> tests =  {
		{1,-2,3,-2},
		{5,-3,5},
		{-3,-2,-3},
	};

	vector<int> expected = {
		3,
		10,
		-2
	};
	assert(expected.size() == tests.size());
	const int N = tests.size();
	for (int i = 0; i < N; i++){
		int res = sol.maxSubarraySumCircular(tests[i]);
		assert( ( res = sol.maxSubarraySumCircular(tests[i]) == expected[i]) );
		cout << res << "\n";
	}
}

int main(){
    Solution sol;
	// vector<int> nums = {1,-2,3,-2}; // 3
	vector<int> nums = {5,-3,5};
	// int res = sol.maxSubarraySumCircular(nums);
	// cout << res << "\n";
	test(sol);
}
