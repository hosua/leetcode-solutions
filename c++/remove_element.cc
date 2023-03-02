#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int count = 0;
		int left = 0; // index which we are moving our nums
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] == val){
				count++;
			} else {
				nums[left] = nums[i];
				left++;
			}
		}	
		return nums.size() - count;
    }
};
int main(){
	// vector<int> nums = {1, 2, 2, 2, 3, 4, 2, 5, 6, 7, 2, 8};
	vector<int> nums = {0, 1, 2, 2, 2, 2, 3, 0, 4, 2};
	Solution sol;
	for (int num : nums){
		cout << num << " ";
	}
	cout << endl;
	int k = sol.removeElement(nums, 2);
	for (int i = 0; i < k; i++){
		cout << nums[i] << " ";
	}
	cout << endl;
}
