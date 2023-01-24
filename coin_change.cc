#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		// for every amount 0..n, dp stores the minimum # of coins to achieve the amount at ith index
		vector<long long> dp(amount+1, INT_MAX); 
		dp[0] = 0; // base case (0 coins always sums to 0)

		sort(coins.begin(), coins.end(), [](int a, int b){
			return a > b;
		});

		for (int a = 1; a <= amount; a++){
			for (int c : coins){
				if (a - c >= 0){
					dp[a] = min(dp[a], 1+dp[a-c]);
				}
			}
		}

		return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }

	// TLE
	// int coinChange(vector<int>& coins, int amount) {
	// 	map<vector<int>, int> mp;
	// 	vector<vector<int>> possible;

	// 	function <void(int,vector<int>)> dfs;        
	// 	dfs = [&](int sum, vector<int> curr_coins) -> void {
	// 		if (sum > amount){
	// 			return;
	// 		} else if (sum == amount){
	// 			possible.push_back(curr_coins);	
	// 			return;
	// 		}
	// 		for (int coin : coins){
	// 			long long new_sum = (long long) coin + (long long) sum;
	// 			if (new_sum < INT_MAX){
	// 				vector<int> next_coins(curr_coins);
	// 				next_coins.push_back(coin);
	// 				sort(next_coins.begin(), next_coins.end());
	// 				if (mp.find(next_coins) == mp.end()){
	// 					mp[next_coins] = sum + coin;
	// 					dfs(mp[next_coins], next_coins);
	// 				}
	// 			}
	// 		}
	// 	};

	// 	dfs(0, {});

	// 	sort(possible.begin(), possible.end(), [](vector<int> a, vector<int> b){
	// 		return (a.size() < b.size());
	// 	});

	// 	return (possible.size() > 0) ? possible[0].size() : -1;
    // }
private:
};

int main(){
    Solution sol;
	// vector<int> coins = {1,2,5};
	// int amount = 11;
	// vector<int> coins =  {1,2147483647};
	// int amount = 2;
	vector<int> coins = {1,2,5};
	int amount = 100;
	int res = sol.coinChange(coins, amount);
	cout << res << "\n";
}
