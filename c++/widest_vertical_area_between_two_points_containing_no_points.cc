#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		const int N = points.size();
       	sort(points.begin(), points.end(), [&](vector<int> a, vector<int> b){
			return a[0] < b[0];
		});
		int largest_width = 0;
		for (int i = 1; i < N; i++)
			largest_width = max(largest_width, points[i][0] - points[i-1][0]);
		return largest_width;
    }
};

int main(){
    Solution sol;
	vector<vector<int>> points = {{3,1},{9,0},{1,0},{1,4},{5,3},{8,8}};
	int res = sol.maxWidthOfVerticalArea(points);
	cout << res << "\n";
}
