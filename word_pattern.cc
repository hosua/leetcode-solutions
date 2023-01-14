#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string s) {
		stringstream ss(s);
		map<char, string> p_map;
		string word;
		int i = 0, end = pattern.size();
		for ( ; ss >> word; i++){
			char ch = pattern[i];
			if (p_map.find(ch) == p_map.end())
				p_map.insert( {ch, word} );
			else
				if (p_map[ch] != word)
					return false;
		}
		if (i != end)
			return false;
		set<string> s_set;
		for (auto itr = p_map.begin(); itr != p_map.end(); itr++)
			if (s_set.find(itr->second) == s_set.end())
				s_set.insert(itr->second);
			else
				return false;

		return true;
	}
};
int main(){
	string pattern = "abba";
	string s = "dog dog dog dog";
	// string pattern = "jquery";
	// string s = "jquery";
	Solution sol;
	cout << sol.wordPattern(pattern, s);
}
