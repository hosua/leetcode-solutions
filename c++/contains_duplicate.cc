#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
 		set<int> seen;
		for (int num : nums)
			if (seen.find(num) == seen.end())
				seen.insert(num);
			else
				return true;
		return false;
    }
};
int main(){
	Solution sol;

}
