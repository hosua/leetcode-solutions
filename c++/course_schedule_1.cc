#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int num_visited; // if num visited != num courses after traversal, there exists a cycle.
	vector<int> indegree; // count of edges inward edges to nth node
	vector<vector<int>> adj;
public:
	Solution(): num_visited(0) {}
    bool canFinish(int num_courses, vector<vector<int>>& prerequisites) {
		indegree = vector<int>(num_courses);
		adj = vector<vector<int>>(num_courses);

		for (vector<int> edge : prerequisites){
			int src = edge[1], dest = edge[0];
			adj[src].push_back(dest);
			indegree[dest]++;
		}	
		
		queue<int> q;
		for (int course = 0; course < num_courses; course++)
			if (indegree[course] == 0) // add leaves to queue
				q.push(course);

		while (!q.empty()){
			int prereq = q.front(); q.pop();
			num_visited++;
			for (int course : adj[prereq]) 
				if (--indegree[course] == 0) // Kahn's algorithm
					q.push(course);
		}

		return (num_visited == num_courses);
    }
};

int main(){
	Solution sol;
	// int numCourses = 2;
	// vector<vector<int>> prerequisites = { {1,0} }; // true
	// int numCourses = 5;
	// vector<vector<int>> prerequisites = { {1,4}, {2,4}, {3,1}, {3,2} }; // true
	int numCourses = 4;
	vector<vector<int>> prerequisites = { {2,0}, {1,0}, {3,1}, {3,2}, {1,3} }; // false
	cout << sol.canFinish(numCourses, prerequisites) << "\n";
}
