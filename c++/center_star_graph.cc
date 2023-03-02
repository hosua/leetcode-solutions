#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int V;
	map<int, vector<int>> adj_map;
	Graph(vector<vector<int>> edges) : V(1){
		for (vector<int> edge : edges){
			int src = edge[0], dest = edge[1];
			if (adj_map.find(src) == adj_map.end()){
				adj_map.insert({src, {dest}});

				if (adj_map.find(dest) == adj_map.end())
					adj_map.insert({dest, {src}});
				else
					adj_map[dest].push_back(src);
			} else {
				adj_map[src].push_back(dest);

				if (adj_map.find(dest) == adj_map.end())
					adj_map.insert({dest, {src}});
				else
					adj_map[dest].push_back(src);
			}
		}
		V = adj_map.size();
	}

	int getMostNeighbors(){
		int most_neighbors = INT_MIN;
		int most_neighbors_key = -1;
		for (pair<int, vector<int>> node : adj_map){
			int key = node.first;
			int neighbor_size = node.second.size();
			if (neighbor_size > most_neighbors){
				most_neighbors = neighbor_size;
				most_neighbors_key = key;
			}
		}	
		return most_neighbors_key;
	}
};

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       	Graph g(edges); 
		return g.getMostNeighbors();
    }
};

int main(){
	Solution sol;
	vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
	cout << sol.findCenter(edges);
}
