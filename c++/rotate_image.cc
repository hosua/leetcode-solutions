#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> matrix);

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		const int N = matrix.size();
		for (int i = 0; i < N/2; i++){
			for (int j = i; j < N; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
		printMatrix(matrix);
		for (int i = N-1; i > N/2; i--){
			for (int j = i; j >= N/2; j--){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}

		printMatrix(matrix);
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N/2; j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][N-j-1];
				matrix[i][N-j-1] = temp;
			}	
		}
    }
};

void printMatrix(vector<vector<int>> matrix){
	for (int i = 0; i < matrix.size(); i++){
		for (int j = 0; j < matrix.size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){
	Solution sol;
	vector<vector<int>> matrix = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	printMatrix(matrix);
	sol.rotate(matrix);
	printMatrix(matrix);
}
