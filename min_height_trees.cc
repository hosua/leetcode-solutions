#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int num_nodes;
	vector<vector<int>> adj_list;
	map<int, vector<int>> height_map; // <height, roots with height>
	vector<int> in_degree;
	Graph(int n, vector<vector<int>> edges) : num_nodes(n){
		in_degree.resize(num_nodes, 0);
		adj_list.resize(num_nodes);
		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
			in_degree[src]++;
			in_degree[dest]++;
		}
	}

	vector<int> getCentroids(){
		vector<int> leaves = getLeaves();	
		vector<int> centroids = BFS(leaves);
		cout << "centroids: ";
		for (int i = 0; i < centroids.size(); i++){
			cout << centroids[i] << " ";
		}
		cout << endl;
		return {};
	}

private:
	vector<int> BFS(vector<int> leaves){

	}
	vector<int> getLeaves(){
		vector<int> leaves;
		for (int src = 0; src < num_nodes; src++){
			if (in_degree[src] == 1){
				leaves.push_back(src);
			}
		}
		return leaves;
	}
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		Graph g(n, edges);
		vector<int> min_roots;
		g.getCentroids();
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
