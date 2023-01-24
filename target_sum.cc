#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	int findTargetSumWays(vector<int>& nums, int target) {
		int total = accumulate(nums.begin(), nums.end(), 0);

		const int N = nums.size();
		vector<vector<int>> memo(N);
		for (vector<int>& m : memo)
			m = vector<int>((2*total)+1, INT_MIN);

		function <int(int,int)> rec;
		rec = [&](int i, int sum) -> int {
			if (i == N){
				return (sum == target);
			} 

			// if we already memoized this sum, then get that value
			if (memo[i][sum + total] != INT_MIN)
				return memo[i][sum + total];
			
			// Otherwise, calculate the memo
			int add = rec(i+1, sum+nums[i]);
			int sub = rec(i+1, sum-nums[i]);
			memo[i][sum+total] = add + sub;
			return memo[i][sum+total];
		};
		return rec(0, 0);
    }

	// TLE
	int findTargetSumWaysTLE(vector<int>& nums, int target) {
		int count = 0;
		const int N = nums.size();
		function <void(int,int)> rec;
		rec = [&](int idx, int sum) -> void {
			if (idx == N){
				if (sum == target)
					count++;
				return;
			}

			rec(idx+1, sum+nums[idx]);
			rec(idx+1, sum-nums[idx]);
		};
		rec(0, 0);
		return count;
    }
};

int main(){
    Solution sol;
	vector<int> nums = {1,1,1,1,1};
	int target = 3; // 5
	// vector<int> nums = {0,0,0,0,0,0,0,0,1};
	// int target = 1; // 256
	int res = sol.findTargetSumWays(nums, target);
	cout << res << "\n";
}
