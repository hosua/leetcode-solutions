#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
	// stupid solution
    // bool isAnagram(string s, string t) {
	// 	if (s.size() != t.size())
	// 		return false;
    //    	map<char, int> s_map, t_map;
	// 	for (int i = 0; i < s.size(); i++){
	// 		char s_ch = s[i];
	// 		char t_ch = t[i];
	// 		if (s_map.find(s_ch) == s_map.end()){
	// 			s_map.insert({s_ch,1});
	// 		} else {
	// 			s_map[s_ch]++;
	// 		}
	// 		if (t_map.find(t_ch) == t_map.end()){
	// 			t_map.insert({t_ch,1});
	// 		} else {
	// 			t_map[t_ch]++;
	// 		}
	// 	}
	// 	for (auto itr = s_map.begin(); itr != s_map.end(); itr++){
	// 		char ch = itr->first;
	// 		int freq = itr->second;
	// 		if ((t_map.find(ch) != t_map.end())){
	// 			if (freq != t_map[ch])
	// 				return false;
	// 		} else {
	// 			return false;
	// 		}
	// 	}
	// 	return true;
    // }
	
	// why the fuck didnt i just do this lol
	bool isAnagram(string s, string t){
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};

int main(){
	string s = "anagram";
	string t = "nagaram";
	Solution sol;
	cout << sol.isAnagram(s, t);
}
