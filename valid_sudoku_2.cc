#include <bits/stdc++.h>
using namespace std;

#define N 9
class Solution {
private:
	bool checkHorizontal(int y, vector<vector<char>> board){
		set<char> seen_set;
		for (int i = 0; i < N; i++){
			char cell = board[y][i];
			if (cell != '.'){
				if (seen_set.find(cell) == seen_set.end())
					seen_set.insert(cell);
				else 
					return false;
			}
		}
		return true;
	}
	bool checkVertical(int x, vector<vector<char>> board){
		set<char> seen_set;
		for (int i = 0; i < N; i++){
			char cell = board[i][x];
			if (cell != '.'){
				if (seen_set.find(cell) == seen_set.end())
					seen_set.insert(cell);
				else 
					return false;
			}

		}
		return true;
	}
	bool check3x3(int x, int y, vector<vector<char>> board){
		set<char> seen_set;
		for (int i = y; i < y+3; i++){
			for (int j = x; j < x+3; j++){
				char cell = board[i][j];
				if (cell != '.'){
					if (seen_set.find(cell) == seen_set.end())
						seen_set.insert(cell);
					else 
						return false;
				}
			}	
		}
		return true;
	}	
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < N; i++){
			if (!checkHorizontal(i, board) || !checkVertical(i, board))
				return false;
		}
		for (int i = 0; i <= 6; i += 3)
			for (int j = 0; j <= 6; j += 3){
				if (!check3x3(i, j, board))
					return false;
			}
		return true;
    }
};

int main(){
	Solution sol;
	/*
	vector<vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}};
	*/
	vector<vector<char>> board = {
		{'.','.','.','.','5','.','.','1','.'},
		{'.','4','.','3','.','.','.','.','.'},
		{'.','.','.','.','.','3','.','.','1'},
		{'8','.','.','.','.','.','.','2','.'},
		{'.','.','2','.','7','.','.','.','.'},
		{'.','1','5','.','.','.','.','.','.'},
		{'.','.','.','.','.','2','.','.','.'},
		{'.','2','.','9','.','.','.','.','.'},
		{'.','.','4','.','.','.','.','.','.'}
	};
	
	cout << sol.isValidSudoku(board);
}
