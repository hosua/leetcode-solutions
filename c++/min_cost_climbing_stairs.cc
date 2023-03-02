#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	int minCostClimbingStairs(vector<int>& cost) {
   		int res = 0;     
		const int N = cost.size();
		vector<int> dp(N+1, -1); // <min_cost>

		function <int(int)> rec = [&](int step) -> int {
			if (step == 0 or step == 1)
				return cost[step];

			if (dp[step] != -1) // don't recurse what we already know
				return dp[step];

			return dp[step] = cost[step] + min(rec(step-2), rec(step-1));
		};
		
		return min(rec(N-1), rec(N-2));
    }
};

int main(){
    Solution sol;
	vector<int> v = {10,15,20};
	int res = sol.minCostClimbingStairs(v);
	cout << res << "\n";
}
