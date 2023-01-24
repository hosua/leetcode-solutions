#include <bits/stdc++.h>
using namespace std;

class UnionFind { 
private:
	int V;
	vector<int> rep;
	vector<size_t> sizes;
public:
	UnionFind(size_t sz){
		V=sz;
		rep = vector<int>(V, 0);
		sizes = vector<size_t>(V, 1);
		for (int i = 0; i < V; i++)
			rep[i] = i;
	}

	int find(int x){
		if (x == rep[x])
			return x;
		return rep[x] = find(rep[x]);
	}

	bool unionize(int a, int b){
		int a_rt = find(a), b_rt = find(b);

		if (a_rt == b_rt)
			return false;

		// preserve lower node index as root 
		if (a < b){
			sizes[a_rt] += sizes[b_rt];
			rep[b_rt] = a_rt;
		} else {
			sizes[b_rt] += sizes[a_rt];
			rep[a_rt] = b_rt;
		}
		// cout << "connected " << a << " <-> " << b << "\n";
		return true;
	}

	bool areConnected(int a, int b){
		return (find(a) == find(b));
	}

	void printReps(){
		for (int i = 0; i < V; i++)
			cout << i << "(" << rep[i] << ")\n";
		cout << "\n";
	}

};

class Solution {
	private:
		int V;
		map<int, vector<int>> val_to_nodes; // <val, [nodes]>
		vector<vector<int>> adj_list;
		vector<int> vals;

		void printAdjList(){
			for (int u = 0; u < V; u++){
				printf("%i: [", u);
				for (int neighbor : adj_list[u])
					printf("%i,", neighbor);
				printf("]\n");
			}
			printf("\n");
		}

		void printValToNodes(){
			for (pair<int,vector<int>> vn : val_to_nodes){
				cout << vn.first << ": [";
				for (int node : vn.second)
					cout << node << ",";
				printf("]\n");
			}
			printf("\n");
		}
	public:
		/*
		 *	A good path is a simple path that satisfies the following conditions:
		 *	The starting node and the ending node have the same value.
		 *	All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
		 *	Return the number of distinct good paths.
		 */
		int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
			this->vals = vals; 
			V = vals.size();;

			UnionFind uf(V);
			adj_list.resize(V);
			for (int i = 0; i < V; i++){
				val_to_nodes[vals[i]].push_back(i);
			}

			for (vector<int> edge : edges){
				int u = edge[0], v = edge[1];
				adj_list[u].push_back(v);
				adj_list[v].push_back(u);;
			}

			// printValToNodes();

			int good_paths = 0;
			for (pair<int, vector<int>> p : val_to_nodes){
				int val = p.first;
				vector<int> nodes = p.second;
				for (int node : nodes){
					for (int neighbor : adj_list[node]){
						if (vals[node] >= vals[neighbor]){
							uf.unionize(node, neighbor);
						}
					}
				}

				unordered_map<int,int> group; // <val, size of group>

				for (int node : nodes)
					group[uf.find(node)]++;

				// for (pair<int,int> p : group)
				// 	cout << "(" << p.first << "," << p.second << ")\n";
				// cout << "\n";

				for (pair<int,int> p : group){
					int val = p.first, sz = p.second;
					good_paths += sz * (sz + 1) / 2;
				}

			}
			// printAdjList();
			// uf.printReps();

			return good_paths;
		}
};
int main(){
	Solution sol;
	vector<int> vals = {1,3,2,1,3};
	vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4}};
	int res  = sol.numberOfGoodPaths(vals, edges);
	cout << res << endl;
}
