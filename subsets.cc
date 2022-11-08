#include <vector>
#include <iostream>
#include <cmath>

using std::vector;

// TODO: I don't understand how this one works
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> sets;
		size_t set_size = nums.size();
		size_t pow_set_size = std::pow(2, nums.size());
		for (int i = 0; i < pow_set_size; i++){
			vector<int> v;
			sets.push_back(v);
			for (int j = 0; j < set_size; j++)
				// Voodoo magic
				if (i & (1 << j))
					sets[i].push_back(nums[j]);
		}
		return sets;
    }
};

int main(){
	vector<int> nums = { 1, 2, 3 };
	Solution sol;
	vector<vector<int>> res = sol.subsets(nums);
	for (auto itr = res.begin(); itr != res.end(); itr++){
		for (auto sub_itr = itr->begin(); sub_itr != itr->end(); sub_itr++){
			std::cout << *sub_itr << ' ';
		}
		std::cout << std::endl;
	}
}
