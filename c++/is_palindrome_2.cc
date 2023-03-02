#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPalindrome(string s) {
		if (check(s))
			return true;
		bool is_left = false;
		int left = 0, right = s.size()-1;
		while (left <= right){
			int delta = right - left;
			cout << left << " " << right << endl;
			string sub = s.substr(left, right - left);
			cout << sub << endl;
			if (is_left){
				left++; 
				is_left = false;
			} else {
				right--;
				is_left = true;
			} 
		}
		return false;
    }

	bool check(string s){
		int left = 0;
		int right = s.size()-1;
		while (left <= right){
			if (s[left] != s[right])
				return false;
			left++; right--;	
		}
		return true;
	}
};

int main(){
	string s = "abca";
	Solution sol;
	cout << sol.validPalindrome(s);
	// cout << sol.check(s);
}
