#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	// TLE 
	vector<int> getRow(int rowIndex) {
   		vector<int> res;     
		vector<vector<int>> tri = {{1}, {1,1}};
		if (rowIndex == 0 or rowIndex == 1)
			return tri[rowIndex];
		for (int i = 2; i <= rowIndex; i++){
			vector<int> row(i+1, 0);
			row[0] = 1, row[i] = 1;
			for (int j = 1; j < i; j++){
				row[j] = tri[i-1][j-1] + tri[i-1][j];
			}		
			tri.push_back(row);
		}

		// for (vector<int> row : tri){
		// 	for (int num : row)
		// 		cout << num << " ";
		// 	cout << "\n";
		// }
		return tri[rowIndex];
    }
};

int main(){
    Solution sol;
	vector<int> row = sol.getRow(3);
	for (int num : row)
		cout << num << " ";
	cout << "\n";
}
