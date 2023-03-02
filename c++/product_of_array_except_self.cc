#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		const int N = nums.size();
		vector<int> res;
		res.resize(N, 1);
		int prefix = 1, postfix = 1;
		for (int i = 0; i < N; i++){
			res[i] = prefix;
			prefix *= nums[i];
		}
		for (int i = N-1; i >= 0; i--){
			res[i] *= postfix;
			postfix *= nums[i];
		}

		return res;	
    }
};
int main(){
	Solution sol;
	vector<int> nums = {1,2,3,4};
	vector<int> res = sol.productExceptSelf(nums);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
