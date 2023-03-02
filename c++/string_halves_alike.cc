#include <bits/stdc++.h>
using namespace std;
class Solution {
	set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
public:
	bool halvesAreAlike(string s) {
		int half = s.size()/2, a = 0, b = 0;	
		for (int i = 0; i < s.size(); i++)
			if (vowels.find(tolower(s[i])) != vowels.end())
				(i < half) ? a++ : b++;
		return (a == b);
	}
};

int main(){
	Solution sol;
	string s = "book";
	cout << sol.halvesAreAlike(s);
}
