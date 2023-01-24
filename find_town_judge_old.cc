#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> adj_list;
public:
    int findJudge(int n, vector<vector<int>>& trust) {
		adj_list.resize(n);
		for (vector<int> t : trust){
			int src = t[0]-1, dest = t[1]-1;
			adj_list[src].push_back(dest);
		}
		for (int i = 0; i < n; i++){
			if (adj_list[i].size() == 0){
				for (int j = 0; j < n; j++){
					if (i != j and 
						find(adj_list[j].begin(), adj_list[j].end(), i) == adj_list[j].end()){
						return -1;
					}
				}
				return i+1;
			}
		}
		return -1;
    }
};

int main(){
	Solution sol;
	// int n = 2; // 2
	// vector<vector<int>> trust = {{1,2}};
	int n = 3;
	vector<vector<int>> trust = {{1,2},{2,3}};
	cout << sol.findJudge(n, trust) << endl;
}
