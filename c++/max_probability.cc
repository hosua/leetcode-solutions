#include <bits/stdc++.h>
using namespace std;

class Solution {
	double max_prob;
	int N;
	vector<vector<pair<int, double>>> adj_list;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		N = n;
       	max_prob = 0; 
		adj_list.resize(N);
		for (int i = 0; i < edges.size(); i++){
			vector<int> edge = edges[i];
			 int src = edge[0], dest = edge[1];
			 double succ = succProb[i];
			 adj_list[src].push_back(make_pair(dest, succ));
			 adj_list[dest].push_back(make_pair(src, succ));
		}

		printAdjList();
		vector<bool> visited(N, false);
	 	DFS(start, end, 1, visited);
		return max_prob;
    }

	void printAdjList(){
		for (int src = 0; src < N; src++){
			vector<pair<int, double>> neighbors = adj_list[src];
			if (neighbors.size()){
				cout << src	<< ": [";
				for (pair<int, double> p : neighbors){
					int neighbor = p.first;
					double wt = p.second;
					cout << "(" << neighbor << "," << wt << "),";
				}
				cout << "]\n";
			}
		}
	}

	void DFS(int node, int target, double prob, vector<bool> visited){
		cout << node << " ";
		visited[node] = true;
		if (node == target and prob > max_prob)
			max_prob = prob;
		for (pair<int, double> pr : adj_list[node]){
			int neighbor = pr.first;
			double p = prob * pr.second;
			if (!visited[neighbor])
				DFS(neighbor, target, p, visited);
		}
	}
};

int main(){
	Solution sol;
	// vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
	// vector<double> succProb = {0.5,0.5,0.2};
	// int n = 3, start = 0, end = 2; // 0.25
	// vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
	// vector<double> succProb = {0.5,0.5,0.3};
	// int n = 3, start = 0, end = 2; // 0.3
	// vector<vector<int>> edges = {{0,1}};
	// vector<double> succProb = {0.5}; 
	// int n = 3, start = 0, end = 2; // 0
	// vector<vector<int>> edges = {{1,4},{2,4},{0,4},{0,3},{0,2},{2,3}};
	// vector<double> succProb = {0.37,0.17,0.93,0.23,0.39,0.04};
	// int n = 5, start = 3, end = 4; // 0.21390
	double res = sol.maxProbability(n, edges, succProb, start, end);
	cout << res << endl;
}
