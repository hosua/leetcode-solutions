#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
 		for (int i = 0; i < nums.size(); i++){
			int left = 0, right = 0;
			for (int j = 0; j < i; left += nums[j++]);
			for (int j = nums.size()-1; j > i; right += nums[j--]);
			if (left == right)
				return i;
		}       
		return -1;
    }
};
int main(){
	// vector<int> v = {1,7,3,6,5,6};
	vector<int> v = {2,1,-1};
	Solution sol;
	cout << sol.pivotIndex(v);
}
