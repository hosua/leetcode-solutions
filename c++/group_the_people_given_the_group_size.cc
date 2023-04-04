#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		const int N = groupSizes.size();
		vector<vector<int>> res;        
		vector<pair<int,int>> pair_vec;
		for (int person = 0; person < N; person++){
			pair_vec.push_back({person, groupSizes[person]});
		}
		sort(pair_vec.begin(), pair_vec.end(), [&](pair<int,int> a, pair<int,int> b){
			return a.second < b.second;
		});

		vector<int> curr_group;
		for (int i = 0; i < pair_vec.size(); i++){
			int person = pair_vec[i].first, group_size = pair_vec[i].second;
			// cout << person << " " << group_size << "\n";
			curr_group.push_back(person);
			if (curr_group.size() == group_size){
				res.push_back(curr_group);
				curr_group.clear();
			}
		}
		// cout << "\n";
		return res;
    }
};


int main(){
    Solution sol;
	// vector<int> groupSizes = {3,3,3,3,3,1,3}; // [[5],[0,1,2],[3,4,6]]
	vector<int> groupSizes = {2,1,3,3,3,2}; // [[1],[0,5],[2,3,4]]
	vector<vector<int>> res = sol.groupThePeople(groupSizes);
	for (vector<int> row : res){
		for (int num : row)
			cout << num << " ";
		cout << "\n";
	}
}
