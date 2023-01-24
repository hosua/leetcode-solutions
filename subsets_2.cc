#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>> s;
   		vector<vector<int>> res;
		function <void(int,vector<int>,vector<int>)> rec =
			[&](int i, vector<int> subseq, vector<int> arr) -> void {
			if (i == arr.size()){
				if (s.find(subseq) == s.end()){
					s.insert(subseq);
					res.push_back(subseq);
				}
				return;
			} 


			subseq.push_back(nums[i]);
			rec(i+1, subseq, arr);
			subseq.pop_back();

			rec(i+1, subseq, arr);
		};
		rec(0, {}, nums);
		return res;
    }
};

int main(){
    Solution sol;
	// vector<int> nums = {1,2,2};
	vector<int> nums = {4,4,4,1,4};

	vector<vector<int>> res = sol.subsetsWithDup(nums);
	for (vector<int> r : res){
		for (int num : r )
			cout << num << " ";
		cout << "\n";
	}
}
