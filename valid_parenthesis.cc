#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
		map<char, char> para_map = { {'{', '}'}, {'(', ')'}, {'[', ']'} };
        stack<char> stk;
		for (char ch : s){
			if (para_map.find(ch) != para_map.end()){
				stk.push(ch);
			} else if (find_if(para_map.begin(), para_map.end(), 
					[ch](const auto& ele){ return ele.second == ch; }) != para_map.end()){
				if (!stk.empty()){
					char expected = para_map[stk.top()];
					stk.pop();
					if (expected != ch){
						return false;
					}
				} else {
					return false;
				}
			}
    	}
		if (!stk.empty())
			return false;
		return true;
	}
};

int main(){
	Solution sol;
	string s = "]";
	cout << sol.isValid(s);
}
