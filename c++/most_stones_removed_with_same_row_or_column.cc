#include <bits/stdc++.h>
using namespace std;

class Solution {
	int N;
	vector<vector<int>> adj_matrix;
public:
    int removeStones(vector<vector<int>>& stones) {
		N = stones.size();
		adj_matrix.resize(N);
		for (int i = 0; i < N; i++){
			adj_matrix[i].resize(N, 0);
		}
       	for (vector<int> stone : stones){
			int x = stone[0], y = stone[1];
		} 
    }
};

int main(){
	Solution sol;
	vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}}; // 5
	// vector<vector<int>> stones = {{0,0},{0,2},{1,1},{2,0},{2,2}}; // 3
	// vector<vector<int>> stones = {{0,0}}; // 0
}
