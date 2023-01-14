#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> moves = {
	{+1,0}, // right
	{-1,0}, // left
	{0,-1}, // up
	{0,+1}, // down
};

class Solution {
	int max_area;
	int M, N;

	void bfs(int x, int y, vector<vector<int>>& grid){
		queue<pair<int,int>> q;
		q.push(make_pair(x,y));	
		grid[y][x] = 2;
		int level = 0;
		while (!q.empty()){
			int breadth = q.size();
			while (breadth--){
				pair<int,int> coord = q.front(); q.pop();
				int px = coord.first, py = coord.second;
				cout << "(" << px << "," << py << ")";
				level++;

				for (pair<int,int> move : moves){
					int new_x = px+move.first, new_y = py+move.second;
					if (new_x < 0 or new_x >= N or new_y < 0 or new_y >= M)
						continue;
					
					pair<int,int> p = make_pair(new_x,new_y);
					if (grid[new_y][new_x] == 1){
						grid[new_y][new_x] = 2;
						q.push(p);
					}
				}
			}
		}
		if (level > max_area)
			max_area = level;
		cout << ": " << max_area << "\n";
	}
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
		max_area = 0;
       	M = grid.size(); 
		N = grid[0].size();
		for (int y = 0; y < M; y++){
			for (int x = 0; x < N; x++){
				int cell = grid[y][x];
				if (cell == 1){
					bfs(x,y, grid);
				}
			}
		}
		return max_area;
    }
};

int main(){
	Solution sol;
	// vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	// 6
	// vector<vector<int>> grid = {{1,1,0,1,1}, {1,0,0,0,0},{0,0,0,0,1},{1,1,0,1,1}}; 
	// 3
	vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
	// 4
	int res = sol.maxAreaOfIsland(grid);
	cout << res << endl;
}
