#include <bits/stdc++.h>
using namespace std;

class Solution {
	int longest_path;
	int N;
	string labels;
	vector<vector<int>> adj_list;
public:
    int longestPath(vector<int>& parent, string s) {
		labels = s;
		longest_path = 0;
		N = parent.size();
		adj_list.resize(N); 
		for (int src = 1; src < N; src++){
			int p = parent[src];
			adj_list[src].push_back(p);
			adj_list[p].push_back(src);
		}
		dfs(0);	
		return longest_path;
    }

	int dfs(int node, int parent=-1){ // returns longest child of subtree of node
		int longest_child = 0, second_longest_child= 0;
		for (int child : adj_list[node]){
			if (child != parent){
				int child_path = dfs(child, node);

				if (labels[child] == labels[node])
					continue;

				if (longest_child < child_path){
					second_longest_child = longest_child;
					longest_child = child_path;
				} else if (second_longest_child < child_path){
					second_longest_child = child_path;
				}
			}
		}
		longest_path = max(longest_path, longest_child+1+second_longest_child);
		return longest_child+1;
	}
};

int main(){
	Solution sol;
	// vector<int> parent = {-1,0,0,1,1,2};
	// string s = "abacbe"; // 3
	// vector<int> parent = {-1,0,0,0};
	// string s = "aabc"; // 3
	vector<int> parent = {-1};
	string s = "z"; // 1
	int res = sol.longestPath(parent, s);
	cout << res << endl;
}
