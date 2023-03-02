#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
       	int right = s.size()-1;
		while (isspace(s[right]))
			right--;
		int count = 0;
		for  ( ; right >= 0 && isalpha(s[right]); right--, count++);
		return count;
    }
};

int main(){
	// string s = "   fly me   to   the moon  ";
	string s = "a ";
	Solution sol;
	cout << sol.lengthOfLastWord(s);
}
