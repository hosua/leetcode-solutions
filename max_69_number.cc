#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	int maximum69Number (int num) {
		int max69 = num;
		string num_str = to_string(num);
		for (int i = 0; i < num_str.size(); i++){
			char ch = num_str[i];
			string cpy = num_str;
			(ch == '6') ? cpy[i] = '9' : cpy[i] = '6';
			int new_num = stoi(cpy);	
			if (new_num > max69)
				max69 = new_num;
		}
		return max69;
	}
};

int main(){
	Solution sol;
	cout << sol.maximum69Number(9969);
}
