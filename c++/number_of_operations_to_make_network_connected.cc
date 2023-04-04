#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<int> degree;
	vector<vector<int>> adj;
public:
	// # of cables = connections.size()
    int makeConnected(int n, vector<vector<int>>& connections) {
		// To make entire network connected, there must be at least n-1 cables for n connections
		if (connections.size()+1 < n)
			return -1;
		
		adj = vector<vector<int>>(n);
		degree = vector<int>(n, 0);
       	for (vector<int> conn : connections){
			int src = conn[0], dest = conn[1];
			adj[src].push_back(dest); adj[dest].push_back(src);
		} 
		
		vector<bool> vis(n, false);
		int islands = 0;
		// BFS 
		for (int i = 0; i < n; i++)
			if (!vis[i]){
				bfs(i, vis);
				islands++;
			}

		// Answer should be number of "islands" - 1 
		return islands-1;
    }
private:

	void bfs(int start, vector<bool>& vis){
		queue<int> q;
		q.push(start);
		while (!q.empty()){
			size_t breadth = q.size();
			while (breadth--){
				int node = q.front(); q.pop();
				vis[node] = true;
				for (int neighbor : adj[node])
					if (!vis[neighbor])
						q.push(neighbor);
			}
		}
	}
};
int main(){
    Solution sol;

}
