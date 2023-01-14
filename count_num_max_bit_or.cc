#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
		const int N = nums.size();
		int max_or = 0;
		int max_or_count = 0;
		vector<vector<int>> subsets = getSubsets(nums);
		for (vector<int> sub : subsets){
			if (sub.size() == 0)
				continue;
			int val = getOrArray(sub);
			if (val > max_or){
				max_or = val;
				max_or_count = 1;
			} else if (val == max_or){
				max_or_count++;
			}
			// cout << val << " " << max_or_count << "\n";
		}
		// cout << endl;
		return max_or_count;
    }

	int getOrArray(vector<int> arr){
		int val = arr[0];
		for (int i = 1; i < arr.size(); i++){
			val |= arr[i];
		}
		return val;	
	}

	vector<vector<int>> getSubsets(vector<int> nums){
		const int N = nums.size();
		vector<vector<int>> subsets;
		subsets.resize(1<<N);
		for (int i = 0; i < (1<<N); i++)
			for (int j = 0; j < N; j++)
				if ((i & (1<<j)))
					subsets[i].push_back(nums[j]);
		return subsets;
	}
};
int main(){
	Solution sol;
	// vector<int> v = {3,1};
	vector<int> v = {2,2,2};
	cout << sol.countMaxOrSubsets(v) << endl;
}
