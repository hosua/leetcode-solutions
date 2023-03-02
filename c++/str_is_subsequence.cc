#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
		int i = 0, j = 0;
		if (s.size() == 0 && t.size() == 0)
			return true;
		while (j < t.size()){
			if (s[i] == t[j])
				i++;
			j++;
		}
		return (i == s.size());
    }
};

int main(){
	// string s = "flw"; string t = "follow";
	// string s = "abc"; string t = "ahbgdc";
	string s = "ab"; string t = "baab";
	Solution sol;
	cout << sol.isSubsequence(s, t);

}
