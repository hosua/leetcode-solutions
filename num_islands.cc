#include <bits/stdc++.h>

using namespace std;
class Solution {
	int R;
	int C;
public:
    int numIslands(vector<vector<char>>& grid) {
		R = grid.size();
		C = grid[0].size();
 		int num_islands = 0;       
		for (int y = 0; y < R; y++){
			for (int x = 0; x < C; x++){
				if (grid[y][x] == '1'){
					cout << "going in " << x << "," << y << endl;
					num_islands++;
					DFS(x, y, num_islands, grid);
				}
			}
		}


		return num_islands;
    }

	void DFS(int x, int y, int& num_islands, vector<vector<char>>& grid){
		cout << x << "," << y << "\t" << num_islands << endl;
		grid[x][y] = '2'; // mark visited
		// up
		if (y-1 >= 0 && grid[y-1][x] == '1'){
			DFS(x, y-1, num_islands, grid);
		}
		// down
		if (y+1 < R && grid[y+1][x] == '1'){
			DFS(x, y+1, num_islands, grid);
		}
		// left
		if (x-1 >= 0 && grid[y][x-1] == '1'){
			DFS(x-1, y, num_islands, grid);
		}
		// right
		if (x+1 < C && grid[y][x+1] == '1'){
			DFS(x+1, y, num_islands, grid);
		}
	}
};


int main(){
	vector<vector<char>> grid = {
	  {'1','1','0','0','0'},
	  {'1','1','0','0','0'},
	  {'0','0','1','0','0'},
	  {'0','0','0','0','1'}
	};
	
	// vector<vector<char>> grid = {
	// 	{1}, {1}
	// };

	Solution sol;
	cout << sol.numIslands(grid);
}
