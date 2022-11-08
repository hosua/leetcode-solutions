#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
	set<string> op_set = {"+", "-", "*", "/"};
	stack<long long int> num_stack;
	stack<string> op_stack;
public:
    int evalRPN(vector<string>& tokens) {
		for (string tok : tokens){
			if (op_set.find(tok) != op_set.end()){
				int b = num_stack.top(); num_stack.pop();
				int a = num_stack.top(); num_stack.pop();
				// do op	
				if (tok == "+"){
					num_stack.push(a + b);
					cout << a << "+" << b << " = " << a + b << endl;
				} else if (tok == "-"){
					num_stack.push(a - b);
					cout << a << "-" << b << " = " << b - a << endl;
				} else if (tok == "*"){
					num_stack.push((long long int)a * (long long int)b);
					cout << a << "*" << b << " = " << a * b << endl;
				} else if (tok == "/"){
					num_stack.push(a / b);
					cout << b << "/" << a << " = " << a / b << endl;
				}
			} else {
				num_stack.push(stoi(tok));
			}
		}		        
		return num_stack.top();
    }
};
int main(){
	Solution sol;
	vector<string> tokens = {"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
	cout << sol.evalRPN(tokens) << endl;
}
