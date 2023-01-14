#include <bits/stdc++.h>
using namespace std;

// TODO

struct Graph {
public:
	int num_courses;
	map<int, vector<int>> adj_list;	
	vector<int> in_degree;
	vector<int> top_sorted;
	Graph(int num_courses) : num_courses(num_courses){
		in_degree.resize(num_courses, 0);
		for (int i = 0; i < num_courses; i++)
			adj_list.insert( {i, {} } );
	};

	void addEdge(int src, int dest){
		adj_list[src].push_back(dest);
		in_degree[dest]++;
	}

	bool isCyclic(){
		bool visited[num_courses];
		memset(visited, false, num_courses);
		bool rec_stack[num_courses];
		memset(rec_stack, false, num_courses);
		for (int course = 0; course < num_courses; course++){
			if (!visited[course] && DFS(course, visited, rec_stack))
				return true;
		}
		return false;
	}

	void printAdjList(){
		for (int course = 0; course < num_courses; course++){
			printf("%i : [", course);
			for (int neighbor : adj_list[course])
				printf("%i,", neighbor);
			printf("]\n");
		}
		printf("\n");
	}
private:
	bool DFS(int course, bool* visited, bool* rec_stack){
		if (!visited[course]){
			visited[course] = true;
			rec_stack[course] = true;
			vector<int> neighbors = adj_list[course];
			for (int neighbor : neighbors){
				if (!visited[neighbor] && DFS(neighbor, visited, rec_stack))
					return true;	
				else if (rec_stack[neighbor])
					return true;	
			}
			top_sorted.push_back(course);
		}
		rec_stack[course] = false;
		return false;
	}
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		Graph g(numCourses);
		for (vector<int> course_pair : prerequisites){
			int course = course_pair[0];
			int prereq = course_pair[1];
			g.addEdge(course, prereq);
		}

		// g.printAdjList();
		if (g.isCyclic()){
			return {};
		}
		return g.top_sorted;
    }
};

int main(){
	Solution sol;
	// int numCourses = 4;
	// vector<vector<int>> prerequisites = { {1,0}, {2,0}, {3,1}, {3,2} };
	// int numCourses = 5;
	// vector<vector<int>> prerequisites = { {1,4}, {2,4}, {3,1}, {3,2} }; // not cyclic
	// int numCourses = 4;
	// vector<vector<int>> prerequisites = { {2,0}, {1,0}, {3,1}, {3,2}, {1,3} }; // cyclic
	// int numCourses = 2;
	// vector<vector<int>> prerequisites {}; // {1,0}
	// int numCourses = 3;
	// vector<vector<int>> prerequisites { {1,0} };
	// int numCourses = 7;
	// vector<vector<int>> prerequisites = {{1,0},{0,3},{0,2},{3,2},{2,5},{4,5},{5,6},{2,4}};
	/*
	 * Output
	 * [6,4,5,2,3,0,1]
	 * Expected
	 * [6,5,4,2,3,0,1]
	 */

	int numCourses = 3;
	vector<vector<int>> prerequisites = {{0,1},{0,2},{1,2}};
	

	vector<int> res = sol.findOrder(numCourses, prerequisites);
	cout << "ORDER: ";
	for (int course : res)
		cout << course << " ";
	cout << "\n";
}
