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

		vector<vector<int>> groups;	
		for (int node = 0; node < V; node++){
			vector<int> curr_group;
			if (!visited[node]){
				DFS(node, curr_group, visited);
				if (curr_group.size())
					groups.push_back(curr_group);
			}
		}

		long long unreachable = 0;
		for (int i = 0; i < groups.size(); i++){
			for (int j = 0; j < groups.size(); j++){
				if (i != j)
					unreachable += groups[i].size() * groups[j].size();
			}
		}

		return unreachable/2;
    }

	void DFS(int node, vector<int>& curr_group, bool* visited){
		visited[node] = true;
		curr_group.push_back(node);

		for (int neighbor : adj_list[node]){
			if (!visited[neighbor]){
				DFS(neighbor, curr_group, visited);
			}
		}
	}
};

int main(){
	Solution sol;

	int n = 7; // expect 14
	vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
	auto res = sol.countPairs(n, edges);
	cout << res << endl;
}
