#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int V;
	vector<int> res, indegree;
	vector<vector<int>> adj;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		V = graph.size();
		adj = vector<vector<int>>(V);
		indegree = vector<int>(V, 0);
		queue<int> q;
		
		for (int node = 0; node < V; node++){ // invert graph edges
			vector<int> neighbors = graph[node];
			for (int neighbor : neighbors){
				adj[neighbor].push_back(node);
				indegree[node]++; // count indegrees so we can start traversal at graph leaves
			}
		}

		printAdj();
		
		for (int node = 0; node < V; node++) // put leaves onto traversal queue
			if (indegree[node] == 0)
				q.push(node);
		
		// BFS traversal
		while (!q.empty()){
			size_t breadth = q.size();
			while (breadth--){
				int node = q.front(); q.pop();
				res.push_back(node);
				for (int neighbor : adj[node])
					if (--indegree[neighbor] == 0) // kahn's algorithm
						q.push(neighbor);
			}
		}
		sort(res.begin(), res.end());
		return res;
    }
private:
	void printAdj(){
		for (int node = 0; node < V; node++){
			printf("%i: [", node);
			for (int neighbor : adj[node])
				printf("%i ", neighbor);
			printf("]\n");
		}
	}
};

int main(){
	Solution sol;
	vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}}; // [2,4,5,6]
	// vector<vector<int>> graph = {{1,2,3,4},{1,2},{3,4},{0,4},{}};
	vector<int> res = sol.eventualSafeNodes(graph);
	for (int num : res){
		cout << num << " ";
	}
	cout << endl;
}
