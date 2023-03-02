#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
		const int N = nums.size();
		vector<int> pre, suff;
		suff.resize(N, 0);
		int sum = 0;
		for (int i = 0; i < N; i++){
			sum += nums[i];
			pre.push_back(sum);
		}
		sum = 0;
		for (int i = N-1; i >= 0; i--){
			sum += nums[i];
			suff[i] = sum;
		}
		pair<int,int> min; // val, idx
		min.first = INT_MAX;
		int i = 0;
		for ( ; i < N-1; i++){
			int a = floor(pre[i]/(i+1));
			int b = floor(suff[i+1]/(N-i-1));
			int avg_diff = abs(a - b);
			if (avg_diff < min.first){
				min.first = avg_diff;
				min.second = i;
			}
		}
		return min.second;
    }
};

int main(){
	Solution sol;
	// vector<int> nums = {2,5,3,9,5,3}; // 3
	vector<int> nums = {1,2,3,4,5}; // 0
	cout << sol.minimumAverageDifference(nums) << endl;
}

