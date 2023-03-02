#include <bits/stdc++.h>
using namespace std;


typedef enum Move {
	UP, DOWN, LEFT, RIGHT
} Move;

vector<Move> moves = {UP,DOWN,LEFT,RIGHT};
class Solution {
private:
	int M, N;
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		M = mat.size();
		N = mat[0].size();
       	vector<vector<int>> res; 
		res.resize(M);
		for (int i = 0; i < M; i++)
			res[i].resize(N);

		for (int y = 0; y < M; y++){
			for (int x = 0; x < N; x++){
				vector<int> distances;
				cout << "(" << x << "," << y << ")\n";
				for (Move move : moves){
					distances.push_back(distFromNearestZero(x,y,move,mat));
				}
				for (int dist : distances){
					cout << dist << " ";
				}
				cout << "\n";
				res[y][x] = *min_element(distances.begin(),distances.end());
			}
		}

		return res;
    }

	int distFromNearestZero(int x, int y, Move move, vector<vector<int>> mat){
		int dist = 0;
		while (mat[y][x] != 0){
			// cout << "(" << x << "," << y << ")\n";
			switch(move){
				case UP:
					y--;
					break;
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case DOWN:
					y++;
					break;
			}

			if (not inBounds(x,y))
				return INT_MAX;
			dist++;
		}
		return dist;
	}

	bool inBounds(int x, int y){
		return (x >= 0 and y >= 0 and x < N and y < M);
	}
};

int main(){
    Solution sol;
	// vector<vector<int>> mat = {{0,0,0},{0,1,0},{0,0,0}};
	// vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
	// vector<vector<int>> mat = {{0}};
	// vector<vector<int>> mat = {{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}};
	/* expected
	[1,0,1,1,0,0,1,0,0,1],
	[0,1,1,0,1,0,1,0,1,1],
	[0,0,1,0,1,0,0,1,0,0],
	[1,0,1,0,1,1,1,1,1,1],
	[0,1,0,1,1,0,0,0,0,1],
	[0,0,1,0,1,1,1,0,1,0],
	[0,1,0,1,0,1,0,0,1,1],
	[1,0,0,0,1,2,1,1,0,1],
	[2,1,1,1,1,2,1,0,1,0],
	[3,2,2,1,0,1,0,0,1,1]
	*/
	vector<vector<int>> mat = {{0,0,1,0,1,1,1,0,1,1},{1,1,1,1,0,1,1,1,1,1},{1,1,1,1,1,0,0,0,1,1},{1,0,1,0,1,1,1,0,1,1},{0,0,1,1,1,0,1,1,1,1},{1,0,1,1,1,1,1,1,1,1},{1,1,1,1,0,1,0,1,0,1},{0,1,0,0,0,1,0,0,1,1},{1,1,1,0,1,1,0,1,0,1},{1,0,1,1,1,0,1,1,1,0}};
	vector<vector<int>> res = sol.updateMatrix(mat);
	for (vector<int> row : res){
		for (int cell : row)
			cout << cell << "|";
		cout << "\n";
	}
}
