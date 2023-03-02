#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	int N;
public:
    string longestPalindrome(string s) {
		N = s.size();
		int start = 0, end = 0;
		for (int i = 0; i < N; i++){
			int l1 = expandAroundCenter(s, i, i);
			int l2 = expandAroundCenter(s, i, i+1);
			int len = max(l1, l2);
			if (len > end){
				start = i - (len-1) / 2;
				end = len;
			}
		}
		return s.substr(start, end);
    }
private:
	int expandAroundCenter(string s, int left, int right){
		int l = left, r = right;
		while (l >= 0 && r < N && (s[l] == s[r])){
			l--;
			r++;
		}
		return r-l-1;
	}
};

int main(){
    Solution sol;
	// string s = "babad";
	string s = "aacabdkacaa";
	string res = sol.longestPalindrome(s);
	cout << res << "\n";
}
