#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int k = nums.size();
		int i = 1, left = 1;
		while (i < nums.size()){
			if (nums[i-1] == nums[i]){
				nums.erase(nums.begin()+i);
				k--;
			} else
				i++;
		}
		return k;
	}
};
int main(){
	vector<int> v = {0,0,0,1,2,2,3,3,3,3,3,3,4};
	Solution sol;
	int k = sol.removeDuplicates(v);
	for (int i = 0; i < k; i++){
		cout << v[i] << " ";
	}
}
