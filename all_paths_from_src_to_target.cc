#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int n;
	vector<vector<int>> adj_list;

	void DFS(int node, int target, bool* visited, bool* rec_stack, vector<int> curr_path, vector<vector<int>>& res){
		visited[node] = true;
		rec_stack[node] = true;
		curr_path.push_back(node);

		for (int neighbor : adj_list[node]){
			if (!visited[neighbor] or !rec_stack[neighbor])
				DFS(neighbor, target, visited, rec_stack, curr_path, res);
		}
		if (node == target){
			res.push_back(curr_path);
		}
		rec_stack[node] = false;
	}

	void printAdjList(){
		for (int i = 0; i < n; i++){
			cout << i << ": [";
			for (int node : adj_list[i])
				cout << node << ", ";
			cout << "]\n";
		}
	}
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> res;
		n = graph.size();
		adj_list.resize(n);
		
		for (int i = 0; i < n; i++)
			adj_list[i] = graph[i];

		// printAdjList();
		
		int start = 0, end = n-1;
		for (int neighbor : adj_list[start]){
			bool visited[n];
			memset(visited, false, n * sizeof(bool));
			bool rec_stack[n];
			memset(rec_stack, false, n * sizeof(bool));
			rec_stack[start] = true;
			visited[start] = true;
			DFS(neighbor, end, visited, rec_stack, {start}, res);
		}
		return res;
    }
};

int main(){
	Solution sol;
	// vector<vector<int>> graph = {{1,2},{3},{3},{}};
	vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
	vector<vector<int>> paths = sol.allPathsSourceTarget(graph);

	for (vector<int> path : paths){
		cout << "[";
		for (int node : path){
			cout << node << ", ";
		}
		cout << "]\n";
	}
}
