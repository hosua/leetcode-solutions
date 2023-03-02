#include <bits/stdc++.h>
using namespace std;

#define ALPHA 26

class Solution {
	string labels;
	vector<vector<int>> adj_list;
	vector<int> res;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
		this->labels = labels;
		res.resize(n);
       	adj_list.resize(n); 
		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
		}

		DFS(0, -1);
		return res;
    }

	vector<int> DFS(int node, int parent){
		// cout << node << endl;
		vector<int> char_counts(ALPHA);
		char node_label = labels[node] - 'a';
		char_counts[node_label]++;

		for (int neighbor : adj_list[node]){
			if (neighbor ==	parent){
				continue;
			}
			vector<int> sub_count = DFS(neighbor, node);
			// for (int c : sub_count){
			// 	cout << c << " ";
			// }
			// cout << endl;
			for (int i = 0; i < ALPHA; i++){
				char_counts[i] += sub_count[i];
			}
		}	
		res[node] = char_counts[node_label];
		return char_counts;
	}
};

int main(){
	Solution sol;
	int n = 7;
	vector<vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
	string labels = "abaedcd";
	vector<int> res = sol.countSubTrees(n, edges, labels);
	for (int num : res){
		cout << num << " ";
	}
	cout << endl;
}
