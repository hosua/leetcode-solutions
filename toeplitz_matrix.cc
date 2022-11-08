#include <bits/stdc++.h>
using namespace std;
class Solution {
	int M;
	int N;
	vector<vector<int>> matrix;
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		this->matrix = matrix;
		N = matrix.size();
		M = matrix[0].size();
		// check top half
		for (int i = 0; i < M; i++){
			if (!checkDiag(0, i)){
				return false;
			}
		}
		// check bottom half
		for (int i = 1; i < N; i++){
			if (!checkDiag(i, 0)){
				return false;
			}
		}
		return true;
    }

	bool checkDiag(int i, int j){
		int first = matrix[i][j];
		// While in bounds
		while(i < N && j < M){
			if (matrix[i][j] != first)
				return false;
			i++, j++;
		}
		return true;
	}
};
int main(){
	Solution sol;
	// vector<vector<int>> matrix = {
	// 	{1,2,3,4},
	// 	{5,1,2,3},
	// 	{9,5,1,2}
	// };
	vector<vector<int>> matrix = {
		{11,74,0,93},
		{40,11,74,7}
	};
	cout << sol.isToeplitzMatrix(matrix);
}
