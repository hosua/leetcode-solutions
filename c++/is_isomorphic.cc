#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		map<char, char> char_map;
		int N = s.size();	
		for (int i = 0; i < N; i++){
			char s_ch = s[i], t_ch = t[i];
			if (char_map.find(s_ch) == char_map.end()){
				char_map.insert( {s_ch, t_ch} );
			} else {
				if (char_map[s_ch] != t_ch)
					return false;
			}
		}
		set<int> seen_vals;
		for (auto itr = char_map.begin(); itr != char_map.end(); itr++){
			if (seen_vals.find(itr->second) == seen_vals.end())
				seen_vals.insert(itr->second);	
			else
				return false;
		}
		return true;
    }
};

int main(){
	Solution sol;
	string s = "paper", t = "title";
	// string s = "badc", t = "baba";
	cout << sol.isIsomorphic(s, t);
}
