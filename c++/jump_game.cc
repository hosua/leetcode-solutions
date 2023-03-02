#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		const int N = nums.size();
		int goal = N-1;
       	for (int i = N-1; i > 0; i--){
			int delta = goal-i; // dist from goal
			if (nums[i-1] > delta){
				goal = i-1; // move goal to valid destination
			}
		} 
		cout << endl;
		return (goal == 0);
    }
};
int main(){
	Solution sol;
	// vector<int> v = {3,2,1,0,4};
	vector<int> v = {2,3,1,1,4};
	cout << sol.canJump(v) << endl;
}
