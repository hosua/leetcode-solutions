#include <bits/stdc++.h>
using namespace std;

class Solution {
	int N;
	vector<vector<char>> board;
public:
	Solution() : N(9){}
	void solveSudoku(vector<vector<char>>& board) {
		this->board = board;
		function <void(int,int,vector<vector<char>>)> dfs;
		dfs = [&](int x, int y, vector<vector<char>> board){

		};

    }

private: 
	bool checkBoard(){
		for (int y = 0; y < N; y++){
			if (not validateRow(y))
				return false;
			for (int x = 0; x < N; x++){
				if ((x % 3 == 0 and y % 3 == 0 and not validateBlock(x,y)) or
						not validateCol(x)) 
					return false;
			}
		}
		return true;	
	}
	bool validateRow(int r){
		set<char> s;
		for (int i = 0; i < N; i++)
			if (board[r][i] != '.' and s.find(board[r][i]) == s.end())
				s.insert(i);
			else
				return false;
		return (s.size() == N);
	}
	bool validateCol(int c){
		set<char> s;
		for (int i = 0; i < N; i++){
			if (board[i][c] != '.' and s.find(board[i][c]) == s.end())
				s.insert(i);
			else 
				return false;
		}
		return (s.size() == N);
	}
	bool validateBlock(int c, int r){
		int br = r/3, bc = c/3;
		set<char> s;	
		// cout << br << "----" << bc << "\n";
		for (int y = br * 3; y < (br*3)+3; y++){
			for (int x = bc * 3; x < (bc*3)+3; x++){
				char cell = board[y][x];
				// cout << board[y][x] << " ";
				if (s.find(cell) == s.end())
					s.insert(cell);
				else
					return false;
			}
			// cout << "\n";
		}
		return (s.size() == N);
	}
};

int main(){
    Solution sol;
	vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
	// vector<vector<char>> board =  {{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};
	sol.solveSudoku(board);
}
