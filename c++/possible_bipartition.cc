#include <bits/stdc++.h>
using namespace std;

/* This solution can be improved if I can figure out how to check all colors while traversing
 * the graph (this solution checks colors after the traversal, which is a waste of time) */

/* BFS actually would have been easier here */

class Graph {
public:
	Graph(int n) : n(n){
		colors.resize(n, 0);
		adj_matrix.resize(n);
		for (vector<bool>& row : adj_matrix){
			row.resize(n, false);
		}
	}

	void addNode(int src, int dest){
		adj_matrix[src][dest] = true;
		adj_matrix[dest][src] = true;
	}

	void printAdjMatrix(){
		for (int src = 0; src < n; src++){
			cout << src+1 << " |";
			for (int dest = 0; dest < n; dest++){
				bool cell = adj_matrix[src][dest];
				cout << cell << " ";
			}
			cout << "|\n";
		}	
	}

	void colorGraph(){
		bool visited[n];
		memset(visited, false, n*sizeof(bool));

		int color = 1;

		for (int src = 0; src < n; src++){
			if (!visited[src])
				DFS(src, color*-1, visited);
		}
	}

	void DFS(int node, int color, bool* visited){
		visited[node] = true;

		if (colors[node] == 0)
			colors[node] = color;
		else if (colors[node] != color)
			return;

		for (int neighbor = 0; neighbor < n; neighbor++)
			if (adj_matrix[node][neighbor] and !visited[neighbor])
				DFS(neighbor, color*-1, visited);
	}

	bool checkColors(){
		for (int src = 0; src < n; src++)
			for (int dest = 0; dest < n; dest++)
				if (adj_matrix[src][dest] and colors[src] == colors[dest])
					return false;

		return true;
	}

private:
	int n;
	vector<vector<bool>> adj_matrix;
	vector<int> colors;
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		Graph g(n);
		for (vector<int> d : dislikes)
			g.addNode(d[0]-1, d[1]-1);

		// g.printAdjMatrix();
		g.colorGraph();
		return g.checkColors();
    }
};

int main(){
	Solution sol;
	int n = 4; // T
	vector<vector<int>> dislikes = {{1,2},{1,3},{2,4}};
	// int n = 3; // F
	// vector<vector<int>> dislikes = {{1,2},{1,3},{2,3}};
	bool res = sol.possibleBipartition(n, dislikes);

	cout << res << endl;
}
