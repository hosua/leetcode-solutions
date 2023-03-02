#include <bits/stdc++.h>
using namespace std;

class Solution {
	int N;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		N = triangle.size();
 		return dfs(triangle); 
    }

	int dfs(vector<vector<int>> triangle, int x=0, int y=0){
		if (y == N){
			return 0;
		}
		int sum = 0;
		int targ = min(triangle[x+1][y+1], triangle[x][y+1]);
		cout << targ << "\t";

		if (targ == triangle[x+1][y+1])
			sum += dfs(triangle, x+1, y+1);
		else
			sum += dfs(triangle, x, y+1);
		cout << sum << "\n";
		return sum+targ;
	}
};
int main(){
    Solution sol;
	vector<vector<int>> triangle = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}};
	int res = sol.minimumTotal(triangle);
	cout << res << "\n";
}
