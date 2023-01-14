#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
		int left = 1;
		while (s.size() > 1 && left < s.size()){
			cout << s << endl;
			if (left > 0 && s[left] == s[left-1]){
				s.erase(left-1, 2);
				left--;
			} else if (s[left] == s[left+1]){
				s.erase(left, 2);
			} else {
				left++;
			}
		}
		return s;
    }
};
int main(){
	// string s = "abbaca";
	// string s = "aaaaaaaaaa";
	string s = "aababaab";
	Solution sol;
	s = sol.removeDuplicates(s);
	cout << "\"" << s << "\"" << endl;
}
