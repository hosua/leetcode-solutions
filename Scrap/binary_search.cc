#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<int> vec;
public:
	Solution(vector<int> vec) : vec(vec){}
	int search(int target, int left, int right){
		int mid = (left+right)/2;

		if (left > right)
			return -1;

		if (target < vec[mid])
			return search(target, left, mid-1);
		else if (target > vec[mid])
			return search(target, mid+1, right);
		else // found match
			return mid;
	}
};

int main(){
	vector<int> nums = {331, 397, 421, 468, 544, 609, 761, 777, 917, 929, 949, 956, 1039, 1044, 1069, 1114, 1126, 1180, 1189, 1509, 1547, 1635, 1695, 1768, 1795, 1799, 2165, 2195, 2224, 2314, 2521, 2724, 2911, 3098, 3107, 3204, 3258, 3268, 3339, 3426, 3463, 3884, 3967, 3983, 4393, 4482, 4541, 4608, 4881, 4883, 5146, 5212, 5295, 5339, 5361, 5368, 5402, 5511, 5567, 5617, 5654, 5765, 5774, 6228, 6395, 6477, 6488, 6546, 6588, 6902, 6907, 7041, 7053, 7079, 7101, 7141, 7234, 7286, 7299, 7311, 7726, 7745, 7786, 7893, 7916, 7983, 8043, 8182, 8633, 8652, 8697, 8756, 8852, 8882, 9008, 9283, 9319, 9605, 9956, 9958};
    Solution sol(nums);
	for (int num : nums){
		int res = sol.search(num, 0, nums.size()-1);
		cout << res << "\n";
	}
}
