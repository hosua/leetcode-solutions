#include <bits/stdc++.h>
using namespace std;

class Solution {
    int M, N;
public:
    bool exist(vector<vector<char>>& board, string word) {
        M = board.size(); // height (y-axis)
        N = board[0].size(); // width (x-axis)
        bool exists = false;
        for (int y = 0; y < M; y++){
            for (int x = 0; x < N; x++){
                exists = DFS(x, y, board, word);
                if (exists)
                    return true;
                // cout << x << " " << y << endl;
                // cout << "------" << endl;
            }
        }
        return false;
    }
    bool DFS(int x, int y, vector<vector<char>>& board, string word, int w_idx=0){
        pair<int,int> coord = make_pair(x,y);
        if (x < 0 || x >= N || y < 0 || y >= M)
            return false;
        char expected_ch = word[w_idx];
        char cell_ch = board[y][x];
        if (expected_ch != cell_ch){
            return false;
        }
        if (w_idx == word.size()-1){
            return true;
        }
        board[y][x] = '.';
        bool res = 
            // left
            DFS(x-1, y, board, word, w_idx+1) || 
            // right
            DFS(x+1, y, board, word, w_idx+1) ||
            // up
            DFS(x, y-1, board, word, w_idx+1) ||
            // down
            DFS(x, y+1, board, word, w_idx+1);
        board[y][x] = cell_ch;
        return res;
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