#include <bits/stdc++.h>
using namespace std;

// Bellman Ford algorithm 
// need to study this, dijkstras, and floyd warshall
class Solution {
private:
	int res;
	int N;
	vector<int> dist;
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		N = n;
		int start = k-1;

		dist = vector<int>(N, INT_MAX);
		dist[start] = 0;
		for (int i = 0; i < N; i++){
			for (vector<int> time : times){
				int src = time[0]-1, dest = time[1]-1, wt = time[2];
				if (dist[src] == INT_MAX)
					continue;
				if (dist[src] + wt < dist[dest])
					dist[dest] = dist[src] + wt;
			}
		}
		int res = INT_MIN;
		for (int num : dist){
			if (num == INT_MAX)
				return -1;
			res = max(res, num);
		}
		return res;
    }
};

int main(){
    Solution sol;
	// vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}}; int n = 4, k = 2; // 2
	// vector<vector<int>> times = {{1,2,1}}; int n = 2, k = 1; // 1
	// vector<vector<int>> times = {{1,2,1}}; int n = 2, k = 2; // -1
	vector<vector<int>> times = {{1,2,1},{2,1,3}}; int n = 2, k = 2; // 3
	int res = sol.networkDelayTime(times, n, k);
	cout << res << endl;
}
