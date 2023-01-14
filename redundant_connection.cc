#include <bits/stdc++.h>
using namespace std;

// 1 through n
class Solution {
public:
	Solution(): n(0){}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			addNode(src, dest);
		}
		
		bool res = isCycle();
		return {INT_MIN, INT_MIN};
    }

	bool isCycle(){

		return false;
	}

private:
	int n;
	vector<vector<int>> adj_list;

	void addNode(int src, int dest){
		if (src >= n or dest >= n){
			n = max(src, dest);
			adj_list.resize(n);
		}
		cout << "Added edge: " << src << "<->" << dest << "\n";
		adj_list[src-1].push_back(dest-1);
		adj_list[dest-1].push_back(src-1);
	}
};

int main(){
	Solution sol;
	vector<vector<int>> edges = {{1,2},{2,3},};
	vector<int> res = sol.findRedundantConnection(edges);
	cout << "[" << res[0] << "," << res[1] << "]\n";
}
