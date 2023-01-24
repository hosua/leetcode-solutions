#include <bits/stdc++.h>
using namespace std;


// TODO
class Solution {
private:
	int N;
	vector<int> flattened;
	int min_moves;
	vector<int> die = {1,2,3,4,5,6};
	
	// flatten 2d vector to make this easier
	void constructFlattened(vector<vector<int>> board){
		int i = 0;
		for (int y = N-1; y >= 0; y--, i++){
			if (i % 2 == 0){
				// right
				for (int x = 0; x < N; x++)
					flattened.push_back(board[y][x]);
			} else {
				// left
				for (int x = N-1; x >= 0; x--)
					flattened.push_back(board[y][x]);
			}
		}
	}

public:
	Solution() : min_moves(INT_MAX){}
	int snakesAndLadders(vector<vector<int>>& board) {
		N = board.size();	
		constructFlattened(board);

		return min_moves;
    }
};

int main(){
    Solution sol;
	vector<vector<int>> board = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};

	sol.snakesAndLadders(board);
}
