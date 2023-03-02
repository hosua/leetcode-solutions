#include <bits/stdc++.h>
using namespace std;

#define ALPHA 26
class Solution {
	string labels;
	vector<int> res;
	vector<vector<int>> adj_list;
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
		DFS();
		return res;
    }

	vector<int> DFS(int node=0, int parent=-1){
		vector<int> total_count(ALPHA);	
		char node_label = labels[node] - 'a';
		total_count[node_label]++;
		for (int child : adj_list[node]){
			// Do not revisit parent node
			if (child != parent){
				vector<int> sub_count = DFS(child, node);	
				for (int i = 0; i < ALPHA; i++){
					total_count[i] += sub_count[i];
				}
			}
		}
		res[node] = total_count[node_label];
		return total_count;
	}
};

int main(){
	Solution sol;
	int n = 4;
	vector<vector<int>> edges = {{0,2},{0,3},{1,2}};
	string labels = "aeed";
	vector<int> res = sol.countSubTrees(n, edges, labels);
	for (int count : res)
		cout << count << " ";
	cout << endl;
}
