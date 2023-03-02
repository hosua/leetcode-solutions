#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> moves = {{+1,0},{-1,0},{0,+1},{0,-1}};

class Solution {
    int M, N;
public:
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size(); // height (y-axis)
        N = board[0].size(); // width (x-axis)
    }
    bool DFS(int x, int y, vector<vector<char>>& board, string word, int i=0){
    }
};

int main(){
    Solution sol;
    // vector<vector<char>> board = {
    //     {'A','B','C','E'},
    //     {'S','F','C','S'},
    //     {'A','D','E','E'}
    // }; 
    // string word = "SEE";
    // vector<vector<char>> board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    // string word = "AAB";
    // vector<vector<char>> board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    // string word = "ABCESEEEFS"; // True
    // vector<vector<char>> board = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}}; 
    // string word = "AAAAAAAAAAAAAAB"; // False
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB"; // True
    cout << sol.exist(board, word) << endl; 
}
