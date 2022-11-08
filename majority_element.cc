#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
		map<int, int> freq_map;
		for (int num : nums){
			if (freq_map.find(num) == freq_map.end())
				freq_map.insert( {num, 1} );
			else
				freq_map[num]++;

			if (freq_map[num] > nums.size()/2)
				return num;
		}
		return INT_MIN;	
    }
};

int main(){
	vector<int> num = {3,2,3};
	Solution sol;
	cout << sol.majorityElement(num);
}
