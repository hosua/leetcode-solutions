#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       	int res = 0; 
		// This works because when you XOR a number with itself, it becomes 0.
		// Therefore the last missing value will be the only number that did
		// not XOR itself.
		for (int i = 0; i < nums.size(); i++)
			res ^= nums[i];
		cout << res << endl;

		for (int i = 0; i <= nums.size(); i++)
			res ^= i;
		cout << res << endl;
		return res;
    }
};

int main(){
	vector<int> v = {0, 5, 2, 3, 4};
	Solution sol;
	cout << sol.missingNumber(v);
}
