#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> moves = {
	{0, -1}, // up
	{0, +1}, // down
	{-1, 0}, // left
	 {1, 0}  // right
};

class Solution {
	int M, N;
public:
    int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		M = grid.size();
		N = grid[0].size();
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (grid[i][j] == '1'){
					// showGrid(grid);
					count++;
					DFS(i, j, grid);
				}
			}
		}
		return count;
    }

	void DFS(int x, int y, vector<vector<char>>& grid){

		grid[x][y] = '2';

		for (pair<int, int> move : moves){
			int nx = x + move.first, ny = y + move.second;
			if (nx < 0 or ny < 0 or nx >= M or ny >= N){
				continue;
			}
			if (grid[nx][ny] == '1')
				DFS(nx, ny, grid);
		}
	}

	void showGrid(vector<vector<char>> grid){
		cout << endl;
		for (vector<char> v : grid){
			for (char cell : v)
				cout << cell << " ";
			cout << endl;
		}
	}
};


int main(){
	// 3
	// vector<vector<char>> grid = {
	//   {'1','1','0','0','0'},
	//   {'1','1','0','0','0'},
	//   {'0','0','1','0','0'},
	//   {'0','0','0','0','1'}
	// };
	
	// 3
	// vector<vector<char>> grid =  {{'1','0','1','1','0','1','1'}}; 
	
	// 1	
	vector<vector<char>> grid = { {1}, {1} };

	Solution sol;
	cout << sol.numIslands(grid);
}
