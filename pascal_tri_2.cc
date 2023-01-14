#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<vector<int>> tri = {{1}, {1,1}};        
		if (rowIndex < tri.size())
			return tri[rowIndex];
		for (int i = 2; i <= rowIndex; i++){
			vector<int> row = {1};
			for (int j = 0; j < tri[rowIndex-1].size()-1; j++){
				row.push_back(tri[rowIndex-1][j]+tri[rowIndex-1][j+1]);
			}
			tri.push_back(row);
		}
		return tri[rowIndex];
    }
};

int main(){
	Solution sol;
	auto res = sol.getRow(3);
	for (int num : res)
		cout << num << " ";
}
