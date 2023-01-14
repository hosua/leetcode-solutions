#include <bits/stdc++.h>
using namespace std;

class Solution {
	int N;
	vector<vector<int>> adj_list;
	stack<int> s;
private:
	vector<int> res;
	void topSort(int node){
	}

	void topSortHelper(int node, bool* visited){
	}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    }
};

int main(){
	Solution sol;
	vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}}; // [2,4,5,6]
	vector<int> res = sol.eventualSafeNodes(graph);
	for (int num : res){
		cout << num << " ";
	}
	cout << endl;
}
