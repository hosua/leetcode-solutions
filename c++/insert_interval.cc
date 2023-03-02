#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		const int N = intervals.size();
		int ni_start = newInterval[0], ni_end = newInterval[1];
		int i = 0;
		int er_start = -1, er_end = -1;
		while (i < N){
			int start = intervals[i][0], end = intervals[i][1];
			if (isOverlapping(start, end, ni_start, ni_end)){
				newInterval[0] = min(newInterval[0], intervals[i][0]);
				newInterval[1] = max(newInterval[1], intervals[i][1]);
				if (er_start == -1){
					er_start = i, er_end = i;
				} else 
					er_end = i;
			}
			i++;
		}
		if (er_start != -1)
			intervals.erase(intervals.begin()+er_start, intervals.begin()+er_end+1);
		intervals.push_back(newInterval);
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
			return a[0] < b[0];
		});
		return intervals;
    }

	bool isOverlapping(int start, int end, int ni_start, int ni_end){
		if ((start >= ni_start and start <= ni_end)
				or (end <= ni_end and end >= ni_start) 
				or (ni_start > start and ni_end < end))
			return true;
		return false;
	}
};

int main(){
    Solution sol;
	// vector<vector<int>> intervals = {{1,3},{6,9}};
	// vector<int> newInterval = {2,5};
	vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<int> newInterval = {4,8};
	// vector<vector<int>> intervals = {{1,5}};
	// vector<int> newInterval = {2,3};
	vector<vector<int>> res = sol.insert(intervals, newInterval);

	for (vector<int> range : intervals){
		cout << "(" << range[0] << "," << range[1] << ")\n";
	}
}
