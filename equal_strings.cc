#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       	string a, b;
		for (string s : word1)
			a += s;
		for (string s : word2)
			b += s;
		return a == b;
    }
};


int main(){
	Solution sol;
	vector<string> a = {"ab", "c"};
	vector<string> b = {"a", "bc"};
	cout << sol.arrayStringsAreEqual(a, b);
}
