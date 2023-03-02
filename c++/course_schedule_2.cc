#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<int> res;
	vector<int> indegree; // for Kahn's top sort
	vector<vector<int>> adj;
public:
    vector<int> findOrder(int num_courses, vector<vector<int>>& prerequisites) {
		adj = vector<vector<int>>(num_courses);
		indegree = vector<int>(num_courses, 0);
		int num_visited = 0; // After traversals, if num_visited != num_courses, then we have a cycle.


		for (vector<int> edges : prerequisites){ // [a,b] where b is prereq of a
			int src = edges[1], dest = edges[0];
			adj[src].push_back(dest);
			indegree[dest]++;
		}
		
		queue<int> q;
		for (int node = 0; node < num_courses; node++) // Add leaves to queue
			if (indegree[node] == 0)
				q.push(node);

		while (!q.empty()){
			size_t breadth = q.size();
			while (breadth--){
				int node = q.front(); q.pop();
				res.push_back(node);
				num_visited++;
				for (int neighbor : adj[node])
					if (--indegree[neighbor] == 0) // Kahn's algo
						q.push(neighbor);
			}
		}

		return (num_visited == num_courses) ? res : vector<int>();
    }
};

int main(){
	Solution sol;
	int num_courses = 4;
	vector<vector<int>> prerequisites = { {1,0}, {2,0}, {3,1}, {3,2} };
	// int num_courses = 5;
	// vector<vector<int>> prerequisites = { {1,4}, {2,4}, {3,1}, {3,2} }; // not cyclic
	// int num_courses = 4;
	// vector<vector<int>> prerequisites = { {2,0}, {1,0}, {3,1}, {3,2}, {1,3} }; // cyclic
	// int num_courses = 2;
	// vector<vector<int>> prerequisites {}; // {1,0}
	// int num_courses = 3;
	// vector<vector<int>> prerequisites { {1,0} };
	// int num_courses = 7;
	// vector<vector<int>> prerequisites = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
	/*
	 * Output
	 * [6,4,5,2,3,0,1]
	 * Expected
	 * [6,5,4,2,3,0,1]
	 */

	// int num_courses = 3;
	// vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2}};
	

	vector<int> res = sol.findOrder(num_courses, prerequisites);
	cout << "ORDER: ";
	for (int course : res)
		cout << course << " ";
	cout << "\n";
}
