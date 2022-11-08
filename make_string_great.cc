#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
       	if (s.size() == 1)
			return s;
		int i;
		while ( (i = findBadIdx(s)) != -1)
			s.erase(i, 2);
		return s;
    }

	int findBadIdx(string s){
		for (int i = 1; i < s.size(); i++){
			int delta = abs(s[i] - s[i-1]);
			if ( delta == 32 && ((islower(s[i]) && isupper(s[i-1])) || (isupper(s[i]) && islower(s[i-1]))) )
				return i-1;	
		}	
		return -1;
	}
};

int main(){
	// string s = "leEeetcode";
	string s = "abBAcC";
	Solution sol;
	cout << sol.makeGood(s);
	// cout << sol.findBadIdx(s);
}
