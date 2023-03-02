#include <bits/stdc++.h>
using namespace std;

// Might be able to do this more cleanly
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		int i = 0;
		int left = 0;
		int zero_count = 0;

		for (int i = 0; i < nums.size(); i++)
			(nums[i] != 0) ? nums[left++] = nums[i] : zero_count++;

		for (int i = nums.size()-1; zero_count > 0; zero_count--, i--)
			nums[i] = 0;	
    }
};

int main(){
	// vector<int> v = {0,1,0,3,12};
	vector<int> v = {0,0,4,0,0,1,2,1};
	Solution sol;
	sol.moveZeroes(v);
	for (int n : v){
		cout << n << " ";
	}
}
