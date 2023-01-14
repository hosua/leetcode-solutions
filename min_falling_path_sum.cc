#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> moves = {
	{+1, +1},
	{0, +1},
	{-1, +1}
};

// TLE, will need to start learning some DP.
class Solution {
	int N;
	int min_path;
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
		min_path = INT_MAX;
       	N = matrix.size(); 
		for (int x = 0; x < N; x++){
			DFS(x, 0, 0, matrix);
		}
		return min_path;
    }

	void DFS(int x, int y, int sum, vector<vector<int>> matrix){
		if (x < 0 or x >= N or y < 0 or y >= N){
			return;
		}
		int val = matrix[y][x];
		sum += val;
		if (y == N-1 and sum < min_path){
			min_path = sum;	
		}

		for (pair<int,int> move : moves){
			int new_x = x + move.first, new_y = y + move.second;
			DFS(new_x, new_y, sum, matrix);
		}
	}
};

int main(){
	Solution sol;
	vector<vector<int>> mat = {{2,1,3},{6,5,4},{7,8,9}};
	int res = sol.minFallingPathSum(mat);
	cout << res << endl;
}
