#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
 		vector<vector<int>> rows;       
		rows.resize(numRows);
		rows[0] = {1};
		if (numRows == 1)
			return rows;
		rows[1] = {1, 1};
		if (numRows == 2)
			return rows;

		for (int i = 2; i < numRows; i++){
			rows[i].push_back(1);
			for (int j = 1; j < rows[i-1].size(); j++){
				int left = rows[i-1][j-1];
				int right = rows[i-1][j];
				rows[i].push_back(left + right);
				cout << rows[i-1][j-1] << endl;
			}
			rows[i].push_back(1);
		}
		return rows;
    }
};
int main(){
	Solution sol;
	vector<vector<int>> res = sol.generate(3);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++){
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
