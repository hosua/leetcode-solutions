#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
		const int N = nums.size();
		vector<vector<int>> res;
		unordered_map<int, int> mp; // <val, freq>
		
		for (int num : nums)
			mp[num]++;

		while (!mp.empty()){
			vector<int> erase_these;
			vector<int> row;
			for (auto& [val, freq] : mp){
				row.push_back(val);
				freq--;
				if (freq == 0){
					erase_these.push_back(val);
				}
			}
			res.push_back(row);

			for (int val : erase_these)
				mp.erase(val);
		}
		return res;
    }
};

int main(){
    Solution sol;
	vector<int> nums = {1,3,4,1,2,3,1};
	vector<vector<int>> res = sol.findMatrix(nums);
	for (vector<int> row : res){
		for (int cell : row)
			cout << cell << " ";
		cout << "\n";
	}
}
