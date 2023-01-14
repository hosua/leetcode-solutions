#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int min_height;
	int num_nodes;
	vector<vector<int>> adj_list;
	vector<int> root_heights;
	Graph(int n, vector<vector<int>> edges) : num_nodes(n){
		min_height = INT_MAX;
		adj_list.resize(num_nodes);
		root_heights.resize(num_nodes, 0);
		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
		}
	}

	void getHeights(){
		for (int root = 0; root < num_nodes; root++){
			int height = 0;
			bool visited[num_nodes];
			memset(visited, false, num_nodes);
			DFS(root, height, visited);
			root_heights[root] = height; 
			if (min_height > height)
				min_height = height;
		}
	}

private:
	void DFS(int node, int& height, bool* visited, int depth=0){
		visited[node] = true;	
		vector<int> neighbors = adj_list[node];
		if (depth > height)
			height = depth;
		for (int neighbor : neighbors){
			if (!visited[neighbor])
				DFS(neighbor, height, visited, depth+1);
		}
	}
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
       	vector<int> min_roots; 
		Graph g(n, edges);
		g.getHeights();
		// cout << "min height: " << g.min_height << endl;
		for (int root = 0; root < g.root_heights.size(); root++)
			if (g.root_heights[root] == g.min_height)
				min_roots.push_back(root);
		return min_roots;
    }
};
int main(){
	Solution sol;
	int n = 4;
	vector<vector<int>> edges = { {1,0}, {1,2}, {1,3} }; // 1
	// int n = 6;
	// vector<vector<int>> edges = { {3,0}, {3,1}, {3,2}, {3,4}, {5,4} }; // 3 4
	vector<int> min_heights = sol.findMinHeightTrees(n, edges);
	for (int num : min_heights)
		cout << num << " ";
	cout << "\n";
}
