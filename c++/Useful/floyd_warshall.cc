#include <bits/stdc++.h>
using namespace std;


// TODO: I suck ass
// https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm 
// https://github.com/SUNGOD3/Floyd-Warshall-bitset-speedup
class Solution {
private:
	int V, Q;
	vector<bool> res;
	vector<vector<int>> dp;
public:
    vector<bool> checkIfPrerequisite(int num_courses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		Q = queries.size();
		V = num_courses;	
		res = vector<bool>(Q, false);
		dp = vector<vector<int>>(V+1, vector<int>(V+1, 0));
		
		for (int i=0; i<prerequisites.size(); i++){
			int src = prerequisites[i][0], dest = prerequisites[i][1];
			dp[src][dest]=1;
		}

		// Floyd Warshall
		for (int k=0; k<V; k++)
			for (int i=0; i<V; i++)
				for (int j=0; j<V; j++)
					dp[i][j] = dp[i][j] or (dp[i][k] and dp[k][j]);

		for (int i = 0; i < Q; i++){
			int src = queries[i][0], dest = queries[i][1];
			res[i] = dp[src][dest];
		}
		
		return res;
    }

private:
		bool search(int src, int dest){
			return (dp[src][dest]);
		}
		void floydWarshall(int i=0, int j=0, int k=0){
			for (int k = 1; k <= V; k++)
				for (int i = 1; i <= V; i++)
					for (int j = 1; j <= V; j++)
						if (dp[i][j] > dp[i][k] + dp[k][j])
							dp[i][j] = dp[i][k] + dp[k][j];
		};

	void printFloyd(){
		cout << " |";
		for (int i = 0; i < V; i++)
			cout << i << " ";
		cout << "\n";
		for (int i = 0; i < V; i++){
			cout << i << "|";
			for (int j = 0; j < V; j++)
				cout << dp[i][j] << " ";;
			cout << "\n";
		}
	}
};

int main(){
    Solution sol;
	// int num_courses = 2;
	// vector<vector<int>> prereq = {{1,0}}, queries = {{0,1},{1,0}}; // 0 1
	// int num_courses = 3;
	// vector<vector<int>> prereq = {{1,2},{1,0},{2,0}}, queries = {{1,0},{1,2}}; // 1 1
	// int num_courses = 2; 
	// vector<vector<int>> prereq = {}, queries = {{1,0},{0,1}}; // 0 0
	int num_courses = 5;
	vector<vector<int>> prereq = {{0,1},{1,2},{2,3},{3,4}}, queries = {{0,4},{4,0},{1,3},{3,0}};
	vector<bool> res = sol.checkIfPrerequisite(num_courses, prereq, queries); 
	// Output: [false,false,false,false]
	// Expected: [true,false,true,false]
	cout << "Results: \n";
	for (bool r : res)
		cout << r << " ";
	cout << "\n";
}
