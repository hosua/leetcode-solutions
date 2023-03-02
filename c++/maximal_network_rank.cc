#include <bits/stdc++.h>
using namespace std;

class Solution {
	int V;
	vector<int> degree;
	vector<vector<int>> adj;
	int res;
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
		res = 0;
		V = n;
		adj = vector<vector<int>>(V);
		degree = vector<int>(V, 0);
		for (vector<int> road : roads){
			int src = road[0], dest = road[1];
			adj[src].push_back(dest);
			adj[dest].push_back(src);
			degree[src]++;
			degree[dest]++;
		}
		
		set<int> vis;
		int cities = 0; // 2 max
		for (int mx = *max_element(degree.begin(), degree.end()); mx > 0; mx--){
			for (int i = mx; i >= 0; i--){
				if (degree[i] == mx){
					cities++;
					vis.insert(i);
					for (int neighbor : adj[i]){
						if (vis.find(neighbor) == vis.end())
							res++;
						vis.insert(neighbor);
					}
				}
				if (cities > 2){
					cout << res << "\n";
					return res;
				}
			}
		}

		// printAdj();
		// printDegree();
		cout << res << "\n";
		return res;
    }

	void printAdj(){
		cout << "ADJ:\n";
		for (int i = 0; i < V; i++){
			cout << i << ": ["; 
			for (int neighbor : adj[i])
				cout << neighbor << " ";
			cout << "]\n";
		}
	}
	void printDegree(){
		cout << "DEGREE:\n";
		for (int i = 0; i < V; i++)
			cout << i << " ";
		cout << "\n";
		for (int r : degree)
			cout << r << " ";
		cout << "\n";
	}
};

void test(){
    Solution sol;
	vector<vector<int>> roads;
	int n, res, i = 0;
	n = 4;
	roads = {{0,1},{0,3},{1,2},{1,3}}; // 4
	cout << "test #" << ++i << "\n";
	res = sol.maximalNetworkRank(n,roads);
	cout << "result: " << res << "\n";
	assert(res == 4);

	n = 5; 
	roads = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}}; // 5
	cout << "test #" << ++i << "\n";
	res = sol.maximalNetworkRank(n,roads);
	cout << "result: " << res << "\n";
	assert(res == 5);

	n = 8;
	roads = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}}; // 5
	cout << "test #" << ++i << "\n";
	res = sol.maximalNetworkRank(n,roads);
	cout << "result: " << res << "\n";
	assert(res == 5);

	n = 2; 
	roads = {{1,0}}; // 1
	cout << "test #" << ++i << "\n";
	res = sol.maximalNetworkRank(n,roads);
	cout << "result: " << res << "\n";
	assert(res == 1);

}

int main(){
    Solution sol;
	// int res = sol.maximalNetworkRank(n, roads);
	// cout << res << "\n";
	test();
}
