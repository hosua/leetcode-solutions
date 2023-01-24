#include <bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int>> grid){
	for (vector<int> row : grid){
		for (int num : row)
			cout << num;
		cout << "\n";
	}
	cout << "------------\n";
}

vector<pair<int,int>> moves = {
	{+1,0},{-1,0},{0,+1},{0,-1}
};


// TODO: This problem is kinda tricky and needs work

class Solution {
private:
	int M, N;
public:
	int shortestBridge(vector<vector<int>>& grid) {
		M = grid.size(), N = grid[0].size();
   		int res = INT_MAX;     
		int marker = 2;
		for (int y = 0; y < M; y++){
			for (int x = 0; x < N; x++){
				int cell = grid[y][x];
				if (cell == 1)
					markIsland(x,y,marker++,grid);

			}
		}
		vector<int> possible_bridges = {};
		printGrid(grid);
		for (int y = 0; y < M; y++){
			for (int x = 0; x < N; x++){
				if (isShore(x,y,grid)){
					int bridge = 0;
					possible_bridges.push_back(findShortestBridge(x,y,grid));
				}
			}
		}

		printShores(grid);
		return *min_element(possible_bridges.begin(), possible_bridges.end());
    }

	int findShortestBridge(int start_x, int start_y, vector<vector<int>> grid){

		queue<pair<int,int>> q;
		q.push(make_pair(start_x,start_y));
		
		vector<vector<bool>> visited(M);
		for (int i = 0; i < M; i++)
			visited[i] = vector<bool>(N, false);
		int level = 0;
		while (!q.empty()){
			pair<int,int> p = q.front();
			int x = p.first, y = p.second;
			visited[y][x] = true;
			int breadth = q.size();
			while (breadth--){
				for (pair<int,int> move : moves){
					int nx = x+move.first, ny = y+move.second;
					if (inBounds(nx,ny) and grid[ny][nx] == 0 and not visited[ny][nx]){
						q.push(make_pair(ny,nx));
					}
				}
			}
			level++;
		}

		return level;
	}

	void markIsland(int x, int y, int marker, vector<vector<int>>& grid){
		if (not inBounds(x,y))
			return;
		int& cell = grid[y][x];
		if (cell != 1)
			return;

		cell = marker;
		for (pair<int,int> move : moves){
			int nx = x+move.first, ny = y+move.second;
			markIsland(nx,ny,marker,grid);
		}
	}

	bool isShore(int x, int y, vector<vector<int>> grid){
		for (pair<int,int> move : moves){
			int nx = x + move.first, ny = y + move.second;
			if (not inBounds(nx,ny))
				continue;
			if (grid[y][x] != 0 and grid[ny][nx] == 0)
				return true;
		}
		return false;	
	}

	bool inBounds(int x, int y){
		return (x >= 0 and y >= 0 and x < N and y < M);
	}

	void printShores(vector<vector<int>> grid){
		for (int y = 0; y < grid.size(); y++){
			for (int x = 0; x < grid[y].size(); x++)
				cout << isShore(x,y,grid);
			cout << "\n";
		}
		cout << "------------\n";
	}
};


int main(){
    Solution sol;

	// vector<vector<int>> grid = {{0,1},{1,0}}; // -> 1
	// vector<vector<int>> grid = {{0,1,0},{0,0,0},{0,0,1}}; // -> 2
	vector<vector<int>> grid = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}}; // -> 1
	int res = sol.shortestBridge(grid);
	cout << res << endl;
}
