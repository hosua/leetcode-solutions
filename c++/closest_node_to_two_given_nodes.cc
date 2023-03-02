#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
		const int N = edges.size();
		vector<bool> vis1(N, false), vis2(N, false);
		vector<int> dist1(N, INT_MAX), dist2(N, INT_MAX);
		dist1[node1] = 0, dist2[node2] = 0;
		int min_node = -1, min_dist = INT_MAX;

       	function <void(int,vector<int>&,vector<bool>&)> dfs;
		dfs = [&](int node, vector<int>& dist, vector<bool>& vis) -> void {
			vis[node] = true;
			int neighbor = edges[node];
			if (neighbor != -1 and not vis[neighbor]){
				dist[neighbor] = dist[node]+1;
				dfs(neighbor,dist,vis);
			}
		};

		dfs(node1, dist1, vis1);
		dfs(node2, dist2, vis2);

		for (int node = 0; node < N; node++){
			int m = max(dist1[node], dist2[node]);
			if (min_dist > m){
				min_node = node;
				min_dist = m;
			}
		}

		return min_node;
    }
};

int main(){
    Solution sol;
	// vector<int> edges = {2,2,3,-1};
	// int node1 = 0, node2 = 1; // 2
	// vector<int> edges = {1,2,-1};
	// int node1 = 0, node2 = 2; // 2
	// vector<int> edges = {4,3,0,5,3,-1};
	// int node1 = 4, node2 = 0; // 4
	vector<int> edges = {2,0,0};
	int node1 = 2, node2 = 0; // 0
	int res = sol.closestMeetingNode(edges, node1, node2);
	cout << res << "\n";
}
