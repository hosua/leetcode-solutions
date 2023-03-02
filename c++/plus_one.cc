#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int right = digits.size()-1;
		// add 1
		digits[right]++;
		bool carry = (digits[right] == 10) ? carry = true : carry = false;
		while (carry){
			int& digit = digits[right];
			if (digit == 10){
				digit = 0;
				carry = true;	
				if (right == 0)
					break;
				else
					digits[--right]++;
			} else {
				carry = false;
				break;
			}
		}
		if (digits[0] == 0)
			digits.insert(digits.begin(), 1);
		return digits;
	}
};

int main(){
	Solution sol;
	vector<vector<int>> nums = { {1,2,3}, {8,9,9,9}, {5}, {9}, {9,9} };
	for (vector<int>& num : nums){
		sol.plusOne(num);
		for (int digit : num)
			cout << digit << " ";
		cout << endl;
	}
}
