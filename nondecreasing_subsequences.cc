#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> res;

		function <void(vector<int>,vector<int>,int)> backtrack = 
			[&](vector<int> nums, vector<int> subseq, int i) -> void {
			if (i == nums.size()){
				if (subseq.size() >= 2 and s.find(subseq) == s.end()){
					res.push_back(subseq);
					s.insert(subseq);			
				}
				return;
			}
			
			// if new subsequence is non-decreasing, recurse 
			if (subseq.empty() or subseq.back() <= nums[i]){ 
				subseq.push_back(nums[i]);
				backtrack(nums, subseq, i+1);
				subseq.pop_back();
			}

			backtrack(nums, subseq, i+1);
		};
		backtrack(nums, {}, 0);
		return res;
    }

private:
    set<vector<int>> s; 
};

int main(){
    Solution sol;
	vector<int> nums = {4,6,7,7};
	vector<vector<int>> res = sol.findSubsequences(nums);
	for (vector<int> subseq : res){
		for (int num : subseq)
			cout << num << " ";
		cout << "\n";
	}

	cout << "\n";
}
