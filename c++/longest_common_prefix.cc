#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string shortest = *min_element(strs.begin(), strs.end(), 
							[] (const string& a, const string &b) { return a.size() < b.size(); });
		int slen = shortest.size();
    }
};

int main(){
	Solution sol;
	vector<string> v = {"flower", "flow", "flight"};
	// vector<string> v = {"dog","racecar","car"};
	cout << sol.longestCommonPrefix(v);
}
