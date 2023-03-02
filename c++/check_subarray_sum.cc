#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) { 
		// <remainder, index>, {0,-1} handles the edge case where the first element is a multiple of k.
		map<int, int> remainder_map = { {0, -1} }; 
		int accum_sum = 0;
		for (int i = 0; i < nums.size(); i++){
			accum_sum += nums[i];
			int rem = accum_sum % k;
			// If we have already found the remainder previously, then we must have a subarray that sums to a multiple of k.
			//   Consider:  a % k, and k = 6.
			// If you take 23 % 6, 29 % 6, 35 % 6, ... 
			// Remainders:    5       5       5   <-- duplicate remainders
			// Notice that the difference between a_1, a_2 are multiples of k.
			// Therefore there must exist an accumulated sum between a_1, a_2, and a_3 that are multiples of k.
			if (remainder_map.find(rem) == remainder_map.end())
				remainder_map.insert( {rem, i} );
			// Before returning true, we must check that our sum is a subarray of length > 1.
			else if (i - remainder_map[rem] > 1)
				return true;
		}
		return false;
    }
};


int main(){
	vector<int> v = {23,2,4,6,7}; int k = 6;
	Solution sol;
	cout << sol.checkSubarraySum(v, k);
}


