#include <bits/stdc++.h>
using namespace std;


set<pair<int, int>> moves = {
	{0, -1}, // up
	{0, 1}, // down
	{-1, 0}, // left
	{1, 0}, // right
};


void printGrid(vector<vector<int>> grid){
	cout << "--------------\n";
	for (vector<int> row : grid){
		for (int cell : row)
			cout << cell << " ";
		cout << "\n";
	}	
	cout << "--------------\n";
}

/* An island in grid2 is considered a sub-island if there is an island in grid1 
 * that contains all the cells that make up this island in grid2.
 */

class Solution {
	int M, N;
	public:
	int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
		M = grid1.size();
		N = grid1[0].size();
		int count = 0;
		for (int i = 0; i < M; i++){
			for (int j = 0; j < N; j++){
				if (grid2[i][j] == 1 and DFS(i, j, grid1, grid2)){
					cout << "Found island at: (" << j << "," << i << ")\n";
					count++;
				}
			}
		}
		return count;
	}

	bool DFS(int x, int y, vector<vector<int>> grid1, vector<vector<int>>& grid2){
		if (!grid1[x][y])
			return false;
		grid2[x][y] = 2;

		for (pair<int, int> move : moves){
			int dest_x = x + move.first, dest_y = y + move.second;
			if (dest_x < 0 or dest_y < 0 or dest_x >= N or dest_y >= M){
				continue;
			}
			if (grid2[dest_x][dest_y] == 1 and 
				!DFS(dest_x, dest_y, grid1, grid2)){
				return false;
			}
		}
		return true;
	}
};

int main(){
	Solution sol;
	// expect 3
	// vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
	// vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};
	
	// expect 2
	// vector<vector<int>> grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
	// vector<vector<int>> grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
	
	// expect 0
	vector<vector<int>> grid1 = {{1,1,1,1,0,0},{1,1,0,1,0,0},{1,0,0,1,1,1},{1,1,1,0,0,1},{1,1,1,1,1,0},{1,0,1,0,1,0},{0,1,1,1,0,1},{1,0,0,0,1,1},{1,0,0,0,1,0},{1,1,1,1,1,0}};
	vector<vector<int>> grid2 = {{1,1,1,1,0,1},{0,0,1,0,1,0},{1,1,1,1,1,1},{0,1,1,1,1,1},{1,1,1,0,1,0},{0,1,1,1,1,1},{1,1,0,1,1,1},{1,0,0,1,0,1},{1,1,1,1,1,1},{1,0,0,1,0,0}};
	printGrid(grid1);	
	printGrid(grid2);

	int res = sol.countSubIslands(grid1, grid2);
	cout << "result: " << res << endl;
}
