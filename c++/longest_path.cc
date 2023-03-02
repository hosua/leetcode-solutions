#include <bits/stdc++.h>
using namespace std;

// Revisit this problem
class Solution {
	int N;
	string labels;
	vector<vector<int>> adj_list;
	int longest_path;
public:
    int longestPath(vector<int>& parent, string s) {
		longest_path = 1;
		labels = s;
		N = parent.size();
		adj_list.resize(N);
		// 0 is always root
		for (int node = 1; node < N; node++){
			int p = parent[node];
			adj_list[node].push_back(p);
			adj_list[p].push_back(node);
		}
		dfs();
		return longest_path;
    }

	int dfs(int node=0, int parent=-1){ // returns longest path of the current node
		int longest = 0, second_longest = 0;

		for (int child : adj_list[node]){
			int longest_child = 0;
			// do not traverse back to the parent
			if (child == parent)
				continue;
			// however, every child needs to be traversed incase the longest path exists
			// within
			else 
				longest_child = dfs(child, node);
			// do not traverse children with same character as current node
			if (labels[child] == labels[node])
				continue;
			if (longest_child > longest){
				second_longest = longest;
				longest = longest_child;
			} else if (longest_child > second_longest){
				second_longest = longest_child;
			}
		}
		longest_path = max(longest_path, longest+1+second_longest);
		return longest+1;
	}
};

int main(){
	Solution sol;
	// string s = "abacbe"; 
	// vector<int> parent = {-1,0,0,1,1,2}; // 3
	// string s = "aabc"; 
	// vector<int> parent = {-1,0,0,0}; // 3
	string s = "aab";
	vector<int> parent = {-1,0,1}; // 2
	int res = sol.longestPath(parent, s);
	cout << res << endl;
}
