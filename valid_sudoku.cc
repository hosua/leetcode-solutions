#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		int N = board.size();
		for (int i = 0; i <= 6; i += 3){
			for (int j = 0; j <= 6; j += 3){
				if (!check_3x3(i, j, board))
					return false;
			}
		}
		// check horizontal
		for (int i = 0; i < N; i++){
			set<int> num_set;
			for (int j = 0; j < N; j++){
				int cell = board[i][j];
				if (cell != '.'){
					if (num_set.find(cell) == num_set.end())
						num_set.insert(cell);
					else
						return false;
				}
			}
		}

		// check vertical
		for (int i = 0; i < N; i++){
			set<int> num_set;
			for (int j = 0; j < N; j++){
				int cell = board[j][i];
				if (cell != '.'){
					if (num_set.find(cell) == num_set.end())
						num_set.insert(cell);
					else
						return false;
				}
			}
		}
		return true;
    }

	bool check_3x3(int ix, int jx, vector<vector<char>> board){
		set<int> num_set;
		for (int i = ix; i < ix+3; i++){
			for (int j = jx; j < jx+3; j++){
				int cell = board[i][j];
				if (cell != '.'){
					if (num_set.find(cell) == num_set.end())
						num_set.insert( {board[i][j]} );	
					else 
						return false;
				}
			}
		}
		return true;
	}
};

int main(){
	vector<vector<char>> board =
		{{'5','3','.','.','7','.','.','.','.'}
		,{'6','.','.','1','9','5','.','.','.'}
		,{'.','9','8','.','.','.','.','6','.'}
		,{'8','.','.','.','6','.','.','.','3'}
		,{'4','.','.','8','.','3','.','.','1'}
		,{'7','.','.','.','2','.','.','.','6'}
		,{'.','6','.','.','.','.','2','8','.'}
		,{'.','.','.','4','1','9','.','.','5'}
		,{'.','.','.','.','8','.','.','7','9'}};

	Solution sol;
	cout << sol.isValidSudoku(board);
}
