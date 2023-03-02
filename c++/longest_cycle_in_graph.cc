#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
	int longestCycle(vector<int>& edges) {
		const int N = edges.size();
   		int longest_cycle = -1;     
		vector<int> indegree(N, 0);
		vector<bool> vis(N, false);

		for (int src = 0; src < N; src++){
			int neighbor = edges[src];
			if (neighbor != -1){
				indegree[neighbor]++;
			}
		}

		// Kahn's Algo
		function <void()> kahns = [&]() -> void {
			queue<int> q;
			for (int src = 0; src < N; src++){
				if (indegree[src] == 0){
					q.push(src);
				}
			}
			while (not q.empty()){
				int node = q.front(); q.pop();
				vis[node] = true;
				int neighbor = edges[node];
				if (neighbor == -1)
					continue;

				indegree[neighbor]--;
				if (indegree[neighbor] == 0)
					q.push(neighbor);
			}
		};

		function <void(int,int)> dfs = [&](int node, int itr) -> void {
			vis[node] = true;
			int neighbor = edges[node];
			if (neighbor == -1)
				return;
			if (not vis[neighbor])
				dfs(neighbor, itr+1);
			else 
				longest_cycle = max(longest_cycle, itr);

		};

		kahns();

		for (int src = 0; src < N; src++){
			if (indegree[src]){
				if (not vis[src]){
					dfs(src,1);
				}
			}
		}
		
		return longest_cycle;
    }


	// TLE (But better)
	// int longestCycle(vector<int>& edges) {
	// 	const int N = edges.size();
   	// 	int longest_cycle = -1;     
	// 	vector<bool> vis(N, false);
	// 	function <void(int,int,unordered_map<int,int>)> dfs = [&](int node, int itr, unordered_map<int,int> mp){
	// 		vis[node] = true;
	// 		// cout << node << "->";
	// 		int neighbor = edges[node];
	// 		if (neighbor == -1)
	// 			return;
	// 		if (not vis[neighbor]){
	// 			mp[neighbor] = mp[node]+1;	
	// 			dfs(neighbor, itr+1, mp);
	// 		} else if (mp.find(neighbor) != mp.end()){
	// 			longest_cycle = max(longest_cycle, itr-mp[neighbor]+1);
	// 		}
	// 	};
	// 	for (int i = 0; i < N; i++){
	// 		unordered_map<int,int> mp; // <node, index seen in traversal>
	// 		mp[i] = 0;
	// 		if (not vis[i])
	// 			dfs(i,0,mp);
	// 		// cout << "\n";
	// 	}
	// 	// cout << "\n";
	// 	return longest_cycle;
    // }

	// TLE
	// int longestCycle(vector<int>& edges) {
	// 	const int N = edges.size();
   	// 	int longest_cycle = -1;     
	// 	function <void(int,int,map<int,int>)> dfs = [&](int node, int itr, map<int,int> mp){
	// 		if (node == -1)
	// 			return;
	// 		if (mp.find(node) != mp.end()){
	// 			longest_cycle = max(longest_cycle,itr-mp[node]);
	// 			return;
	// 		}
	// 		mp[node] = itr;
	// 		// cout << node << "->";
	// 		int neighbor = edges[node];
	// 		dfs(neighbor, itr+1, mp);
	// 	};
	// 	for (int i = 0; i < N; i++){
	// 		map<int,int> mp; // <node, index seen in traversal>
	// 		mp[i] = 0;
	// 		if (mp.find(i) == mp.end())
	// 			dfs(i,0,mp);
	// 		// cout << "\n";
	// 	}
	// 	// cout << "\n";
	// 	return longest_cycle;
    // }
};

int main(){
    Solution sol;
	// vector<int> edges = {3,3,4,2,3}; // 3
	// vector<int> edges = {2,-1,3,1}; // -1
	vector<int> edges = {3,4,0,2,-1,2}; // 3
	int res = sol.longestCycle(edges);
	cout << res << "\n";
}
