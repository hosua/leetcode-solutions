#include <bits/stdc++.h>
using namespace std;
class Solution {
	int M, N;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		M = mat.size();
		N = mat[0].size();
		vector<int> res;
		traverse(0,0,1,mat,res);
		return res;
    }
	void traverse(int x, int y, int dir, vector<vector<int>> mat, vector<int>& res){
		if (x < 0){
			x += 1, dir *= -1;
		}
		if (y < 0){
			y += 1, dir *= -1;
		}
		if (x >= N){
			y -= 1, dir *= -1;
		}
		if (y >= M){
			y -= 1, dir *= -1;
		}

		if (x == N and y < 0){
			y += 2, x -= 1, dir *= -1;
		}
		// cout << dir << endl;
		// cout << "(" << x << "," << y << ")" << endl;
		int cell = mat[y][x];
		cout << cell << "(" << x << "," << y << ")" << endl;
		res.push_back(cell);
		if (x == N-1 and y == M-1)
			return;
		if (dir == 1){ // upright
			traverse(x+1, y-1, dir, mat, res);
		} else { // downleft
			traverse(x-1, y+1, dir, mat, res);
		}

	}
};

int main(){
	Solution sol;
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> res = sol.findDiagonalOrder(matrix);
	for (int num : res){
		cout << num << endl;
	}
}
