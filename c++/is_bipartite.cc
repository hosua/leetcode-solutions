#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution() : n(0){}

    bool isBipartite(vector<vector<int>>& graph) {
		n = graph.size();
		adj_list.resize(n);
		colors.resize(n);

		for (int src = 0; src < n; src++){
			for (int dest : graph[src])
				addNode(src, dest);
		} 
		
		int color = 1;
		bool visited[n];
		memset(visited, false, n*sizeof(bool));

		for (int node = 0; node < n; node++){
			if (!visited[node] and !BFS(node, color*-1, visited)){
				return false;
			}
		}

		return true;
    }
private:

	bool BFS(int start, int color, bool* visited){
		queue<int> q;
		q.push(start);	
		while (!q.empty()){
			int breadth = q.size();
			while (breadth--){
				int node = q.front();
				q.pop();
				visited[node] = true;
				if (colors[node] == 0)
					colors[node] = color;	

				for (int neighbor : adj_list[node]){
					if (!visited[neighbor]){
						q.push(neighbor);
					} else if (colors[node] == colors[neighbor]){
						cout << "Same adjacent color detected at nodes: " << node << " & " << neighbor << "\n";
						return false;
					}
				}
			}
			color *= -1;
		}
		return true;
	}

	void addNode(int src, int dest){
		// cout << "Added edge: " << src << "->" << dest << "\n";
		adj_list[src].push_back(dest);
		adj_list[dest].push_back(src);
	}

	int n;
	vector<int> colors;
	vector<vector<int>> adj_list;
};


int main(){
	Solution sol;
	vector<vector<int>> graph = {{1,2,3},{0,2},{0,1,3},{0,2}}; // F
	// vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}}; // T
	// vector<vector<int>> graph = {{1},{0,3},{3},{1,2}}; // T
	bool res = sol.isBipartite(graph);
	cout << "result: " << res << "\n";
}
