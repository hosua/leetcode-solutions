#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       	vector<int> undefeated;
		vector<int> one_loss;

		map<int, int> win_map;
		map<int, int> lose_map;
		for (vector<int> match : matches){
			int winner = match[0];
			int loser = match[1];
				
			if (win_map.find(winner) == win_map.end())
				win_map.insert({winner, 1});
			else 
				win_map[winner]++;
			
			if (lose_map.find(winner) == lose_map.end())
				lose_map.insert({winner, 0});

			if (lose_map.find(loser) == lose_map.end())
				lose_map.insert({loser, 1});
			else
				lose_map[loser]++;
			
			if (win_map.find(loser) == win_map.end())
				win_map.insert({loser, 0});
		}

		for (pair<int, int> loser : lose_map){
			int player = loser.first;
			int lose_count = loser.second;
			if (lose_count == 0)
				undefeated.push_back(player);
			else if (lose_count == 1)
				one_loss.push_back(player);
		}
		return {undefeated, one_loss};
    }
};
int main(){
	Solution sol;
	vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
	vector<vector<int>> res = sol.findWinners(matches);
	vector<int> undefeated = res[0];
	vector<int> one_loss = res[1];
	cout << "undefeated : " << endl;
	for (int ele : undefeated)
		cout << ele << ", ";
	cout << endl << endl;
	cout << "one loss: " << endl;
	for (int ele : one_loss)
		cout << ele << ", ";
	cout << endl;
}
