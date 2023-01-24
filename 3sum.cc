#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
		const int N = nums.size();
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					int iv = nums[i], jv = nums[j], kv = nums[k];
					if (i != j and j != k and i != k and
						((iv + jv + kv) == 0)){
						vector<int> triplet = {iv,jv,kv};
						sort(triplet.begin(), triplet.end());
						if (find(res.begin(), res.end(), triplet) == res.end())
							res.push_back(triplet);
					}
				}
			}
		}
		return res;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {-1,0,1,2,-1,-4};

	vector<vector<int>> res = sol.threeSum(nums);


}
