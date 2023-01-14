#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
		const int N = nums.size();
		vector<long long > pre(N+1), suff(N+1);

		for (int i = 0; i < N; i++){
			pre[i+1] = pre[i] + nums[i];
		}
		for (int i = N-1; i >= 0; i--){
			suff[i] = suff[i+1] + nums[i];
		}
		cout << endl;
		pair<int,int> min(INT_MAX, -1); // val, idx
		
		for (int i = 0; i < N; i++){
			long long a = floor(pre[i+1]/(i+1));
			cout << pre[i] << "/" << (i+1) << "=" << a << endl;
			long long b = (i == N-1) ? suff[i+1] : floor(suff[i+1]/(N-i-1));
			cout << suff[i+1] << "/" << N-i-1 << "=" << b << endl;
			cout << a << " " << b << " ";
			int avg_diff = int(abs(a - b));
			cout << avg_diff << " ";
			cout << endl;
			if (avg_diff < min.first){
				min.first = avg_diff;
				min.second = i;
				// cout << min.first << " " << min.second << endl;
			}
		}
		cout << "\n";
		// N = 7
		// let i=0
		// i+1 = 1 => 2/1 = 2
		// n-i-1 = 6 => 29/6 = 5
		// [2,  7,  10, 19, 24, 27, 31]
		// [31, 29, 24, 21, 12, 7,  4]
		for (int num : pre)
			cout << num << " ";
		cout << "\n";
		for (int num : suff)
			cout << num << " ";
		cout << "\n";
		return min.second;
    }
};

int main(){
	Solution sol;
	// vector<int> nums = {2,5,3,9,5,3}; // 3
	vector<int> nums = {1,2,3,4,5}; // 0
	cout << sol.minimumAverageDifference(nums) << endl;
}
