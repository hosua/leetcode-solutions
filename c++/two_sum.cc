#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> res;
		// <delta, index>
		map<int, int> delta_map;        
		for (int i = 0; i < nums.size(); i++){
			if (delta_map.find(nums[i]) == delta_map.end())
				delta_map.insert({target - nums[i], i});
			else {
				res = {delta_map[nums[i]], i};
				break;
			}
		}
		return res;
    }
};

int main(){
	vector<int> v = {2,7,11,15}; int target = 9;
	Solution sol;
	vector<int> res = sol.twoSum(v, target);
	cout << "[" << res[0] << "," << res[1] << "]" << endl;
}
