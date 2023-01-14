#include <bits/stdc++.h>
using namespace std;

class Solution {
	vector<vector<int>> adj_list;
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		if (source == destination)
			return true;
		adj_list.resize(n);

       	for (vector<int> e : edges){
			adj_list[e[0]].push_back(e[1]);
			adj_list[e[1]].push_back(e[0]);
		} 
		
		bool visited[n];
		memset(visited, false, n * sizeof(bool));

		for (int neighbor : adj_list[source])
			if (DFS(neighbor, destination, visited))
				return true;

		return false;
    }

	bool DFS(int node, int target, bool* visited){
		visited[node] = true;
		if (node == target)
			return true;	

		for (int neighbor : adj_list[node])
			if (!visited[neighbor] and DFS(neighbor, target, visited))
				return true;

		return false;
	}
};


int main(){
	Solution sol;
	// int n = 3, source = 0, destination = 2; // T
	// vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
	int n = 6, source = 0, destination = 5; // F
	vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
	bool res = sol.validPath(n, edges, source, destination);
	cout << "result: " << res << "\n";
}
