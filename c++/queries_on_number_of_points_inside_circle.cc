#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		const int N = queries.size();
		vector<int> res(N, 0);
		for (int i = 0; i < N; i++){
			vector<int> query = queries[i];
			int x = query[0], y = query[1], r = query[2];
			for (vector<int> point : points){
				int px = point[0], py = point[1];
				float dist = sqrt(pow((x-px),2)+pow((y-py),2)); // pythogrean theorem
				if (dist <= r)
					res[i]++;
			}
		}
		return res;
    }
};

int main(){
    Solution sol;
	vector<vector<int>> points = {{1,3},{3,3},{5,3},{2,2}}, queries = {{2,3,1},{4,3,1},{1,1,2}}; // [3,2,2]
	vector<int> res = sol.countPoints(points, queries);
	for (int r : res)
		cout << r << " ";
	cout << "\n";
}
