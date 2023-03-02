#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<int>> mat){
	for (int y = 0; y < mat.size(); y++){
		for (int x = 0; x < mat[y].size(); x++)
			cout << mat[y][x];
		cout << "\n";
	}
	for (int i = mat.size(); i--; )
		cout << "-";
	cout << "\n";
}

vector<pair<int,int>> adj = {
	{+1,0},{-1,0},{0,+1},{0,-1}
};

class Solution {
private:
	int M,N;
public:
    int numEnclaves(vector<vector<int>>& grid) {
 		M = grid.size(), N = grid.size();
		int res = 0;
		function <int(int,int,int)> dfs = [&](int x, int y, int count){
			if (reachesBoundary(x,y)){
				count = 0;
				printf("Setting count to 0\n");
				return 0;
			}
			grid[y][x] = 2;
			printf("(%i,%i)\n", x,y);
			printMat(grid);
		 	printf("count %i\n",count);
			for (pair<int,int> p : adj){
				int nx = x+p.first, ny = y+p.second;
				if (not outOfBounds(x,y) and grid[ny][nx] == 1){
					count += dfs(nx,ny,count);
				}
			}
			return count+1;
		};

		for (int y = 1; y < M-1; y++){
			for (int x = 1; x < N-1; x++){
				if (grid[y][x] == 1){
					printf("Going in: (%i,%i)\n", x,y);
					int count = dfs(x,y,0);
					printf("Appending %i starting from coord (%i,%i)\n",count,x,y);
					res += count;
				}
			}
		}
		return res;
    }

	bool reachesBoundary(int x, int y){
		if (x == 0 or y == 0 or x == M-1 or y == N-1)
			printf("(%i,%i) reaches boundary\n",x,y);
		return (x == 0 or y == 0 or x == M-1 or y == N-1);
	}

	bool outOfBounds(int x, int y){
		return not (x >= 0 and y >= 0 and x < M and y < N);
	}
};

int main(){
    Solution sol;
	// vector<vector<int>> grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}}; // 3
	// vector<vector<int>> grid = {{0,1,1,0},{0,0,1,0},{0,0,1,0},{0,0,0,0}}; // 0
	// vector<vector<int>> grid = {{0,0,0,0},{0,0,1,0},{0,0,1,0},{0,1,1,0}}; // 0
	vector<vector<int>> grid = {{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
	// 3
	int res = sol.numEnclaves(grid);
	cout << "result: " << res << endl;
	printMat(grid);
}
