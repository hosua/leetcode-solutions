#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
 		vector<int> res;       
		const int N = nums.size();
		bool *arr = (bool*)calloc(N, sizeof(*arr));
		for (int num : nums)
			arr[num-1] = true;
		for (int i = 0; i < N; i++)
			if (!arr[i])
				res.push_back(i+1);
		free(arr);
		return res;
    }
};

int main(){
	vector<int> v = {4,3,2,7,8,2,3,1};
	Solution sol;
	vector<int> res = sol.findDisappearedNumbers(v);
	for (int num : res)
		cout << num << " ";
}
