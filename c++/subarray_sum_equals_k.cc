#include <bits/stdc++.h>

using namespace std;

// Ensure I understand this when I wake up tomorrow

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int res = 0;
		map<int, int> count_map = { {0, 1} }; // <prefix_sum, count>
		int prefix_sum = 0;
		for (int num : nums){
			prefix_sum += num;
			int sub_k = prefix_sum - k;
			
			if (count_map.find(sub_k) != count_map.end())
				res += count_map[sub_k];

			if (count_map.find(prefix_sum) == count_map.end())
				count_map.insert( {prefix_sum, 1} );
			else
				count_map[prefix_sum]++;
		}
		return res;
    }
};

int main(){
	// vector<int> v = {1,1,1}; int k = 2;
	vector<int> v = {1,2,3}; int k = 3;
	// vector<int> v = {1,-1,1,1,1,1}; int k = 3;
	Solution sol;
	int res = sol.subarraySum(v, k);
	cout << res << endl;

}
