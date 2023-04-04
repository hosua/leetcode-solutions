#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
		const int N = nums.size();
       	vector<int> res;
		vector<int> lhs, piv, rhs;
		for (int i = 0; i < nums.size(); i++){
			int num = nums[i];
			if (num < pivot)
				lhs.push_back(num);
			else if (num > pivot)
				rhs.push_back(num);
			else
				piv.push_back(num);
		}
		res.insert(res.end(), lhs.begin(), lhs.end());
		res.insert(res.end(), piv.begin(), piv.end());
		res.insert(res.end(), rhs.begin(), rhs.end());
		return res;
    }
};
int main(){
    Solution sol;
	vector<int> nums = {9,12,5,10,14,3,10}; int pivot = 10;
	vector<int> res = sol.pivotArray(nums, pivot);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
