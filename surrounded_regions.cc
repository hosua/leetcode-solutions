#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
      	int M = board.size();
		int N = board[0].size();
		for (int y = 1; y < M-1; y++){
			for (int x = 1; x < N-1; x++){
				// cout << "cell: " << cell << endl;
				cout << x << "," << y << endl;
				if (board[y][x] == 'O'){
					board[y][x] = 'X';
				}
			}
		}
    }
};

int main(){
	Solution sol;
	// vector<vector<char>> board ={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
	// [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
	vector<vector<char>> board = {{'O','O','O'},{'O','O','O'},{'O','O','O'}};
	// [["O","O","O"],["O","O","O"],["O","O","O"]]
	for (vector<char> row : board){
		for (char cell : row)
			cout << cell << " ";
		cout << "\n";
	}
}
