#include <bits/stdc++.h>
using namespace std;

// Get centroids of graph, return them.
class Graph {
	int V;
	vector<vector<int>> adj;
	vector<int> degree;

public:
	Graph(int n, vector<vector<int>> edges) : V(n){
		degree.resize(V, 0);
		adj.resize(V);
		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
			degree[src]++;
			degree[dest]++;
		}
	}

	vector<int> getCentroids(){
		vector<int> leaves = getLeaves();	

		cout << "leaves: ";
		for (int leaf : leaves) cout << leaf << " ";
		cout << "\n";

		vector<int> centroids = getCentroidsUtil(leaves);

		cout << "centroids: ";
		for (int i = 0; i < centroids.size(); i++) cout << centroids[i] << " ";
		cout << "\n";

		return centroids;
	}

private:
	vector<int> getCentroidsUtil(vector<int> leaves){
		queue<int> q;
		for (int leaf : leaves)
			q.push(leaf);
		int ht = 0;	
		vector<int> res;
		while (!q.empty()){
			size_t breadth = q.size();
			res.clear();
			while (breadth--){
				int node = q.front(); q.pop();
				res.push_back(node);
				for (int neighbor : adj[node]){
					if (--degree[neighbor] == 1){
						q.push(neighbor);
						res.push_back(neighbor);
					}
				}
			}
			ht++;
		}

		return res;
	}

	vector<int> getLeaves(){
		vector<int> leaves;
		for (int src = 0; src < V; src++)
			if (degree[src] == 1)
				leaves.push_back(src);
		return leaves;
	}
};
class Solution {
private:
									  
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		if (edges.size() == 0)
			return {0};
		Graph g(n, edges);

		vector<int> min_roots;
		vector<int> centroids = g.getCentroids();
		for (int centroid : centroids)
			min_roots.push_back(centroid);
		
		return min_roots;
    }
};

int main(){
	Solution sol;
	// int n = 4;
	// vector<vector<int>> edges = { {1,0}, {1,2}, {1,3} }; // 1
	// int n = 6;
	// vector<vector<int>> edges = { {3,0}, {3,1}, {3,2}, {3,4}, {5,4} }; // 3 4
	int n = 2;
	vector<vector<int>> edges = {{0,1}};
	vector<int> min_heights = sol.findMinHeightTrees(n, edges);
	for (int num : min_heights)
		cout << num << " ";
	cout << "\n";
}
