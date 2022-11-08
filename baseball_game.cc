#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
 		stack<int> s;       
		for (string op : operations){
			cout << op << endl;
			if (op == "C"){
				s.pop();
			} else if (op == "D"){
				s.push(s.top() * 2);
			} else if (op == "+"){
				int temp = s.top();
				s.pop();
				int res = temp + s.top();
				s.push(temp);
				s.push(res);
			} else {
				s.push(stoi(op));
			}
		}
		int sum = 0;
		while (!s.empty()){
			sum += s.top();
			s.pop();
		}
		return sum;
    }
};

int main(){
	Solution sol;
	vector<string> operations = {"5", "2", "C", "D", "+"};
	cout << sol.calPoints(operations);
}
