#include <bits/stdc++.h>
using namespace std;

// TODO: Revisit this 
class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
		long long liters = 0;
		E = roads.size();
		V = E+1;

		adj = vector<vector<int>>(V);
		degree = vector<int>(V, 0);
		rep = vector<int>(V, 1);
		rep[0] = true;

		for (vector<int> road : roads){
			int src = road[0], dest = road[1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
			degree[src]++;
			degree[dest]++;
		}

		function <void()> bfs;
		bfs = [&]() -> void {
			queue<int> q;
			// Add all leaves to the queue
			for (int node = 1; node < V; node++){
				if (degree[node] == 1)
					q.push(node);
			}
			while(!q.empty()){
				size_t breadth = q.size();
				while (breadth--){
					int node = q.front(); q.pop();
					liters += ceil((double)rep[node] / seats);
					for (int neighbor : adj[node]){
						// I don't fully understand the usage of degree here. It's purpose is
						// so that we don't revisit already traversed nodes, however I don't really
						// get how or why it works. It's related to Kahn's Topological sorting algorithm.
						// https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
						rep[neighbor] += rep[node]; // Add reps from current node to the neighbors
						if (--degree[neighbor] == 1 && neighbor != 0)
							q.push(neighbor);
					}
				}
				showRep();
			}
		};

		bfs();
		return liters;
    }

private:
	int V, E;
	
	vector<int> rep;
	vector<vector<int>> adj;
	vector<int> degree;

	void showRep(){
		for (int i = 0; i < V; i++)
			cout << rep[i] << " ";
		cout << "\n";
	}
};

int main(){
    Solution sol;
	// vector<vector<int>> roads = {{0,1},{0,2},{0,3}}; int seats = 5; // 3
	vector<vector<int>> roads = {{3,1},{3,2},{1,0},{0,4},{0,5},{4,6}}; int seats = 2; // 7
	long long res = sol.minimumFuelCost(roads, seats);
	cout << res << "\n";
}
