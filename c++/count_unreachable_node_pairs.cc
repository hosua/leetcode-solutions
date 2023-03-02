#include <bits/stdc++.h>
using namespace std;

class Solution {
	int V, E;
	vector<vector<int>> adj_list;
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
       	V = n; 
		E = edges.size();
		adj_list.resize(n);
		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
		}
		
		bool visited[V];
		memset(visited, false, V * sizeof(bool));

		long long unreachable = 0;
		
		for (int node = 0; node < V; node++){
			if (!visited[node]){
				long long count = 0;
				DFS(node, visited, count);
				// n-count == the number of nodes we did not visit in the DFS traversal
				unreachable += count * ((long long)n-count);
			}
		}

		return unreachable/2;
    }

	void DFS(int node, bool* visited, long long& count){
		if (visited[node])
			return;
		visited[node] = true;
		count++;
		for (int neighbor : adj_list[node]){
			DFS(neighbor, visited, count);
		}
	}
};

int main(){
	Solution sol;

	int n = 7; // expect 14
	vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
	
	// int n = 12;
	// vector<vector<int>> edges = {};
	auto res = sol.countPairs(n, edges);
	cout << res << endl;
}
