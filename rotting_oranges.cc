#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj = {
	{+1,0},{-1,0}, // right, left
	{0,+1},{0,-1} // down, up
};

class Solution {
private:
	bool is_possible;
	int M, N;
	int minutes;
	
	// Returns true of there are still fresh orange(s)
	bool hasFreshOrange(vector<vector<int>> grid){
		for (int y = 0; y < M; y++)
			for (int x = 0; x < N; x++)
				if (grid[y][x] == 1)
					return true;
		return false;
	}

	bool inBounds(int x, int y){
		return (x >= 0 and x < N and y >= 0 and y < M);
	}

	void bfs(vector<vector<int>> grid, vector<vector<int>> parent_state={}){
		// if the current state is the same as the parent state, 
		// it is impossible to rot all oranges.

		if (grid == parent_state){ 			
			is_possible = false;
			return;
		}
		if (not hasFreshOrange(grid)){
			return;
		}
		vector<vector<int>> next_grid_state = grid;
		for (int y = 0; y < M; y++){
			for (int x = 0; x < N; x++){
				int cell = grid[y][x];
				if (cell == 2){
					for (pair<int,int> p : adj){
						int new_x = x + p.first, new_y = y + p.second;
						if (inBounds(new_x,new_y) and grid[new_y][new_x] == 1)
							next_grid_state[new_y][new_x] = 2;
					}
				}
			}
		}
		bfs(next_grid_state, grid);
		minutes++;
	}
public:
	int orangesRotting(vector<vector<int>>& grid) {
		is_possible = true;
       	M = grid.size(), N = grid[0].size(); 
		minutes = 0;
		bfs(grid);
		return (is_possible) ? minutes : -1;
  	}
};


int main(){
    Solution sol;
	vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}}; // 4
	// vector<vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}}; // -1
	// vector<vector<int>> grid = {{1},{1},{1},{1}}; // -1
	// vector<vector<int>> grid = {{0}}; // 0
	// vector<vector<int>> grid = {{0,2}}; // 0
	// vector<vector<int>> grid = {{2},{2},{1},{0},{1},{1}}; // -1
	int res = sol.orangesRotting(grid);
	cout << res << endl;
}
