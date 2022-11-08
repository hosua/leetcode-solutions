#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
		for (int i = 0; i < nums.size()-1; i++){
			for (int j = 0; j < nums.size()-1; j++){
				if (nums[j] > nums[j+1]){
					int temp = nums[j];
					nums[j] = nums[j+1];
					nums[j+1] = temp;
				}	
			}
		}        
    }
};

int main(){	
	Solution sol;
	vector<int> colors = {2,0,2,1,1,0};
	sol.sortColors(colors);
	for (int color : colors)
		cout << color << " ";
	cout << endl;
}
