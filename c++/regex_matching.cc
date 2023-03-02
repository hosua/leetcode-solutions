#include <bits/stdc++.h>
using namespace std;

// TLE
class Solution {
public:
	bool isMatch(string s, string p) {
		return isMatchUtil(s, p);
	}

private:
	bool isMatchUtil(string s, string p){
		if (p == "" and s == "")
			return true;

		bool match = (s != "") and (p[0] == s[0] or p[0] == '.');
		
		// Kleene-star
		if (p.size() >= 2 and p[1] == '*'){
			return isMatchUtil(s, p.substr(2)) or // try no match (don't consider the match var here)
				(match and isMatchUtil(s.substr(1), p)); // try one or more match
		} 
		// if no Kleene-star, then match a single char from p to s	
		return match and isMatchUtil(s.substr(1), p.substr(1));
	}
};

int main(){
	Solution sol;
	// string s = "aa", p = ".*"; // 1
	// string s = "aaa", p = "ab*a*c*a"; // 1
	string s = "aaaaaaaaaaaaaaaaaaab", p = "a*a*a*a*a*a*a*a*a*a*";
	bool res = sol.isMatch(s, p);
	cout << res << "\n";
}
