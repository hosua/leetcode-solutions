#include <bits/stdc++.h>
using namespace std;

class Solution {
	int N;
public:
    int singleNonDuplicate(vector<int>& nums) {
		int res = 0;
		N = nums.size();       
		return binarySearch(0, N-1, nums);	
    }

	int binarySearch(int left, int right, vector<int> nums){
		if (left == right)
			return nums[left];
		int mid = (left+right)/2;	
		if (mid % 2)
			mid--;
		if (!checkAdj(mid, nums))
			return binarySearch(left, mid, nums);
		else
			return binarySearch(mid+2, right, nums);
	}

private:
	bool checkAdj(int mid, vector<int> nums){
		return (nums[mid] == nums[mid+1]);
	}
};

int main(){
    Solution sol;
	// vector<int> nums = {1,1,2,3,3,4,4,8,8};
	vector<int> nums = {1};
	int res = sol.singleNonDuplicate(nums);
	cout << res << "\n";
}
