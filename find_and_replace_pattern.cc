#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	bool checkPattern(string word, string pattern){
		unordered_map<char,char> char_map;
		for (int i = 0; i < word.size(); i++){
			char a = word[i], b = pattern[i];
			if (char_map.find(a) == char_map.end()){
				char_map[a] = b;
				for (pair<char,char> p : char_map)
					if (p.first != a and p.second == b)
						return false;
			} else if (char_map[a] != b)
				return false;
		}
		return true;
	}

public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
		vector<string> res;
       	for (string word : words){
			if (checkPattern(word, pattern))
				res.push_back(word);
		} 
		return res;
    }

};

int main(){
	Solution sol;
	// vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
	// string pattern = "abb";
	vector<string> words = {"a","b","c"};
	string pattern = "a";
	vector<string> res = sol.findAndReplacePattern(words, pattern);
	for (string s : res)
		cout << s << " ";
	cout << endl;
}
