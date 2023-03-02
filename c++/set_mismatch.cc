#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
		vector<int> res;
		set<int> num_set;
		for (int num : nums){
			if (num_set.find(num) == num_set.end()){
				num_set.insert(num);
			} else {
				res.push_back(num);
			}
		}        
		int count = 1;
		for (auto itr = num_set.begin(); itr != num_set.end(); itr++, count++){
			if (*itr != count){
				res.push_back(count);
				break;
			}
		}
		
		if (num_set.size() == 1 && *(num_set.begin()) == 1){
			res.push_back(2);
		}

		if (res.size() == 1)
			res.push_back(nums.size());
		return res;
    }
};

int main(){
	// vector<int> nums = {1,2,2,4};
	// vector<int> nums = {1,1};
	// vector<int> nums = {2,2};
	vector<int> nums = {1,5,3,2,2,7,6,4,8,9};
	Solution sol;
	vector<int> res = sol.findErrorNums(nums);
	for (auto itr = res.begin(); itr != res.end(); itr++){
		cout << *itr << " ";
	}

}
