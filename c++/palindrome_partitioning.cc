#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	vector<vector<string>> partition(string s) {
   		vector<vector<string>> res;     
		function <void(int,vector<string>&)> rec = [&](int start, vector<string>& part) -> void {
			if (start == s.size())
				res.push_back(part);

			for (int end = start; end < s.size(); end++){
				string sub = string(s.begin()+start, s.begin()+end+1);
				if (isPalindrome(sub)){
					part.push_back(sub);
					rec(end+1, part);
					part.pop_back();
				}
			}
		};
		vector<string> part;
		rec(0, part);
		return res;
    }

private:
	bool isPalindrome(string s){
		int left = 0, right = s.size()-1;
		while (left <= right)
			if (s[left++] != s[right--])
				return false;
		return true;
	}
};

int main(){
    Solution sol;
	string s = "aab";
	vector<vector<string>> v = sol.partition(s);
	for (vector<string> part : v){
		for (string s : part)
			cout << s << " ";
		cout << "\n";
	}
	cout << "\n";
}
