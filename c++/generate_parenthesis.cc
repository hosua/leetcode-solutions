#include <bits/stdc++.h>
using namespace std;

// 1: () len == 2
// 2: (()), ()() len == 4
// 3: ((())), (()()), (())(), ()(()), ()()() len == 6
// note that len always == 2*n


class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
		generateParenthesisUtil("", n, res);
		return res;
    }

private:
	void generateParenthesisUtil(string curr, int n, vector<string>& res){
		// every resulting string length must be 2*n
		if (curr.size() == n*2){ 
			if (isValidParenthesis(curr))
				res.push_back(curr);
		} else {
			curr.push_back('(');
			generateParenthesisUtil(curr, n, res);
			curr.pop_back();
			curr.push_back(')');
			generateParenthesisUtil(curr, n, res);
			curr.pop_back();
		}
	}

	bool isValidParenthesis(string curr){
		int bal = 0;
		for (char c : curr){
			if (c == '(')
				bal++;
			else if (c == ')')
				bal--;

			if (bal < 0) // closing bracket came before opening bracket 
				return false;
		}
		return bal == 0;
	}
};

int main(){
    Solution sol;
	// vector<string> res = sol.generateParenthesis(1);
	vector<string> res = sol.generateParenthesis(3);
	for (string r : res)
		cout << r << "\n";
	cout << "\n";
}
