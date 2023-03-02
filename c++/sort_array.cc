#include <bits/stdc++.h>
using namespace std;

#define BIT_SIZE 32

class Solution {
private:
	function <void()> radixSort;
public:
    vector<int> sortArray(vector<int>& nums) {
		// radix sort
		for (int bitdex = 0; bitdex < BIT_SIZE-1; bitdex++){
			vector<vector<int>> neg_buckets(2);
			vector<vector<int>> pos_buckets(2);
			for (int num : nums){
				int bit = (num >> bitdex) & 1;
				// if signed bit is set
				(num >> (BIT_SIZE-1) & 1) ? neg_buckets[bit].push_back(num) : pos_buckets[bit].push_back(num);
			}
			int i = 0;
			for (vector<int> bucket : neg_buckets)
				for (int num : bucket)
					nums[i++] = num;
			for (vector<int> bucket : pos_buckets)
				for (int num : bucket)
					nums[i++] = num;
		}
		return nums;
    }
};


int main(){
    Solution sol;
	// vector<int> v = {5,3,2,1};
	vector<int> v = {-2,3,-5};
	vector<int> res = sol.sortArray(v);
	for (int num : res)
		cout << num << "\n";
}
