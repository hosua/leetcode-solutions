#include <bits/stdc++.h>
using namespace std;

// I FUCKING HATE DP
class Solution {
private:
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int res = INT_MIN;
       	vector<pair<int,int>> players;
		const size_t N = scores.size();
		
		for (int i = 0; i < N; i++)
			players.push_back(make_pair(scores[i], ages[i]));

		sort(players.begin(), players.end(), [](pair<int,int> a, pair<int,int> b){
			if (a.second == b.second)
				return a.first < b.first;
			return a.second < b.second;
		});

		vector<int> dp(N, 0);
		for (int i = 0; i < N; i++){
			dp[i] = players[i].first;
			for (int j = 0; j < i; j++)
				if (players[j].first <= players[i].first)
					dp[i] = max(dp[i], dp[j] + players[i].first);
			res = max(res, dp[i]);
		}
		return res;
    }
};

int main(){
    Solution sol;
	// vector<int> scores = {1,3,5,10,15}, ages = {1,2,3,4,5}; // 34
	// vector<int> scores = {4,5,6,5}, ages = {2,1,2,1}; // 16
	vector<int> scores = {319776,611683,835240,602298,430007,574,142444,858606,734364,896074}, ages = {1,1,1,1,1,1,1,1,1,1};
	int res = sol.bestTeamScore(scores, ages);
	cout << res << "\n";
}
