#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int N;
	vector<vector<bool>> trust_mat;
public:
	int findJudge(int n, vector<vector<int>>& trust) {
		N = n;
		trust_mat.resize(n);
		for (int i = 0; i < n; i++)
			trust_mat[i] = vector<bool>(n, false);

		for (vector<int> t : trust){
			int src = t[0]-1, dest = t[1]-1;
			trust_mat[src][dest] = true;
		}
		// printMat();
		for (int a = 0; a < n; a++){
			bool all_trust = true;
			for (int b = 0; b < n; b++){
				if (a != b and not trust_mat[b][a]){
					all_trust = false;	
					break;	
				}
			}
			if (all_trust){
				bool trust_no_one = true;
				for (int b = 0; b < n; b++){
					if (trust_mat[a][b] == true){
						trust_no_one = false;
						break;
					}
				}
				if (trust_no_one)
					return a+1;
			}
		}
		return -1;
    }

private:
	void printMat(){
		cout << "  ";
		for (int i = 0; i < N; i++)
			cout << i+1 << " ";
		cout << "\n";
		for (int i = 0; i < N; i++){
			cout << i+1 << "|";
			for (int j = 0; j < N; j++)
				cout << trust_mat[i][j] << "|";
			cout << "\n";
		}
	}
};

int main(){
    Solution sol;
	int n = 2; 
	vector<vector<int>> trust = {{1,2}};
	int res = sol.findJudge(n, trust);
	cout << res << "\n";
}
