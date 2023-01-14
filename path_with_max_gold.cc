#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> moves = {
	{-1, 0}, // left
	{+1, 0}, // right
	{0, -1}, // up
	{0, +1}, // down
};
class Solution {
	int M, N;
	int max_path;
public:
    int getMaximumGold(vector<vector<int>>& grid) {
       	max_path = 0; 
		M = grid.size();
		N = grid[0].size();
		vector<vector<int>> visited(M);
		for (int i = 0; i < M; i++){
			visited[i].resize(N, 0);
		}
		for (int y = 0; y < M; y++){
			for (int x = 0; x < N; x++){
				DFS(x, y, 0, grid, visited);
			}
		}
		return max_path;
    }

	void DFS(int x, int y, int sum, vector<vector<int>> grid, vector<vector<int>> visited){
		if (x < 0 or y < 0 or x >= N or y >= M)
			return;
		if (!grid[y][x] or visited[y][x])
			return;
		int cell = grid[y][x];
		visited[y][x] = true;
		sum += cell;
		if (sum > max_path)
			max_path = sum;
		for (pair<int,int> move : moves){
			int new_x = x + move.first, new_y = y + move.second;
			DFS(new_x, new_y, sum, grid, visited);
		}
	}
};

int main(){
	Solution sol;
	vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}}; // 24
	int res =sol.getMaximumGold(grid);
	cout << res << endl;
}
