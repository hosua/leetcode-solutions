#include <bits/stdc++.h>
using namespace std;

struct Graph {
	int N;
	Graph(): N(0){}
	map<int, vector<int>> adj_list;
	void addEdge(int course, int prereq){
		// printf("Added prereq %i to course %i\n", prereq, course);
		if (adj_list.find(course) == adj_list.end()){
			adj_list.insert( {course, {prereq} } );
			if (adj_list.find(prereq) == adj_list.end())
				adj_list.insert( {prereq, vector<int>() } );
		} else
			adj_list[course].push_back(prereq);
	}

	bool isCyclic(){
		// array for keeping track of visited nodes
		bool visited[N];
		// similar to visited array, except it "unvisits" nodes the moment
		// a recursive call is finished. 
		// This is essential for detecting a back-edge (which in turn, means its 
		// cyclic) in a directed graph.
		bool rec_stack[N];
		memset(visited, false, N);
		memset(rec_stack, false, N);

		for (int course = 0; course < N; course++){
			if (!visited[course] && DFS(course, visited, rec_stack))
				return true;
			// cout << endl;
		}
		return false;
	}

	void printAdjList(){
		for (pair<int, vector<int>> node : adj_list){
			printf("%i: [", node.first);
			for (int neighbor : node.second)
				printf("%i,", neighbor);
			printf("]\n");
		}
		printf("\n");
	}
private:	
	// Traverse with DFS and return true if cycle is found
	bool DFS(int course, bool* visited, bool* rec_stack){
		if (!visited[course]){
			visited[course] = true;
			rec_stack[course] = true;
			vector<int> prereqs = adj_list[course];
			for (int prereq : prereqs){
				if (!visited[prereq] && DFS(prereq, visited, rec_stack))
					return true;
				else if (rec_stack[prereq])
					return true;		
			}
		}
		// unset the stack as each recursive call leaves
		rec_stack[course] = false;
		return false;
	}
};
class Solution {
	Graph graph;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		graph.N = numCourses;
       	for (int i = 0; i < prerequisites.size(); i++){
			int course = prerequisites[i][0];
			int prereq = prerequisites[i][1];
			graph.addEdge(course, prereq);
		} 

		graph.printAdjList();

		return (!graph.isCyclic());
    }
};

int main(){
	Solution sol;
	// int numCourses = 2;
	// vector<vector<int>> prerequisites = { {1,0} }; // true
	int numCourses = 5;
	vector<vector<int>> prerequisites = { {1,4}, {2,4}, {3,1}, {3,2} }; // true
	// int numCourses = 4;
	// vector<vector<int>> prerequisites = { {2,0}, {1,0}, {3,1}, {3,2}, {1,3} }; // false
	cout << sol.canFinish(numCourses, prerequisites);
}
