#include <bits/stdc++.h>
using namespace std;

class Solution {
	int res;
	vector<vector<pair<int,bool>>> adj;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
		res = 0;
		adj = vector<vector<pair<int,bool>>>(n);
       	for (vector<int> conn : connections){
			int src = conn[0], dest = conn[1];
			// Make the the graph undirected so that it is traversable
			// but, mark each edge that needs to be flipped as true
			adj[src].push_back({dest, true});
			adj[dest].push_back({src, false});
		} 
		vector<bool> vis(n, false);
		dfs(vis);
		return res;
    }

private:
	void dfs(vector<bool>& vis, int node=0, int parent=-1){
		vis[node] = true;
		for (auto [neighbor, marked] : adj[node]){
			if (!vis[neighbor]){
				// Add to result if the edge needed to be flipped
				res += marked;
				dfs(vis, neighbor, node);
			}
		}	
	}
};

int main(){
    Solution sol;
	int n = 6; vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}}; // 3
	// int n = 5; vector<vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}}; // 2

	int res = sol.minReorder(n, connections);	
	cout << res << "\n";
}
