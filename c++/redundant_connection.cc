#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int N;
	vector<int> rep;

	// return false if a was already unionized with b
	// return true if connection was performed
	bool unionize(int a, int b){
		int a_rt = find(a), b_rt = find(b);
		if (a_rt == b_rt)
			return false;
		// merge set with larger root to set with smaller root 
		// (the condition in which we merge actually does not matter for this problem)
		(a_rt < b_rt) ? rep[b_rt] = a_rt : rep[a_rt] = b_rt;	
		return true;
	}

	int find(int x){
		if (rep[x] == x)
			return x;
		return rep[x] = find(rep[x]);
	}

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		N = edges.size();
		rep.resize(N+1, 0);
		for (int i = 1; i <= N; i++)
			rep[i] = i;
		
		// If unionize returns false, then src was already in the set of dest
		// which means that we found a cycle (i.e., a redundant connection)
       	for (vector<int>& edge : edges){
			int src = edge[0], dest = edge[1];
			if (!unionize(src, dest))
				return edge;
		} 
		return {0,0};
    }
};

int main(){
	Solution sol;
	vector<vector<int>> edges = {{1,2},{1,3},{2,3}}; // Output: [2,3]
	// vector<vector<int>> edges =  {{1,2},{2,3},{3,4},{1,4},{1,5}}; // Output [1,4]
	vector<int> res = sol.findRedundantConnection(edges);
	cout << "(" << res[0] << "," << res[1] << ")\n";
}
