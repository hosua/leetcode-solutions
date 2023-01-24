#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int V, min_path;
	map<int, vector<pair<int,int>>> adj; // src -> {dest, weight}
public:
	int minScore(int n, vector<vector<int>>& roads) {
		function<void(int,vector<bool>&)> dfs = [&](int node, vector<bool>& visited){
			visited[node] = true;
			for (pair<int,int> p : adj[node]){
				int neighbor = p.first, wt = p.second;
				if (wt < min_path)
					min_path = wt;
				if (!visited[neighbor])
					dfs(neighbor, visited);
			}
		};

       	V = n; 
		vector<bool> visited(V, false);
		min_path = INT_MAX;

		for (vector<int> road : roads){
			int u = road[0], v = road[1], wt = road[2];
			adj[u].push_back(make_pair(v, wt));
			adj[v].push_back(make_pair(u, wt));
		}
		
		dfs(1, visited);
		return min_path;
    }
};

int main(){
    Solution sol;
	// vector<vector<int>> roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
	// int n = 4; // 5
	// vector<vector<int>> roads = {{1,2,2},{1,3,4},{3,4,7}};
	// int n = 4; // 2
	// vector<vector<int>> roads = {{4,5,7468},{6,2,7173},{6,3,8365},{2,3,7674},{5,6,7852},{1,2,8547},{2,4,1885},{2,5,5192},{1,3,4065},{1,4,7357}};
	// int n = 6; // 1885
	vector<vector<int>> roads = {{3,2,1},{1,3,3}};
	int n = 3; // 1
	int res = sol.minScore(n, roads);
	cout << res << endl;
}
