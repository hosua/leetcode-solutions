#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
 		sort(score.begin(), score.end(), [&](vector<int> a, vector<int> b){
			return a[k] > b[k];
		});
		return score;
    }
};
int main(){
    Solution sol;
	vector<vector<int>> score = {{10,6,9,1},{7,5,11,2},{4,8,3,15}}; int k = 2;
	vector<vector<int>> res = sol.sortTheStudents(score, k);
	for (vector<int> row : res){
		for (int cell : row)
			cout << cell << " ";
		cout << "\n";
	}
}
