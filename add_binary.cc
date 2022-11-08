#include <iostream>
using std::string;
class Solution {
public:
    string addBinary(string a, string b) {
		const int sz = std::max(a.length(), b.length());
		int i = sz-1;
		int a_idx = a.length()-1, b_idx = b.length()-1;
		string output = "";
		for (int i = 0; i < sz; i++){
			output.push_back('0');
		}
		bool carry = false;
		while (true){
			int a_bit = 0, b_bit = 0;
			if (a_idx >= 0){
				a_bit = a[a_idx] - '0';
				a_idx--;
			}
			if (b_idx >= 0){
				b_bit = b[b_idx] - '0';
				b_idx--;
			}
			int res_bit = a_bit + b_bit;
			if (carry){
				res_bit++;
				if (res_bit > 1){
					res_bit -= 2;
					carry = true;
				} else {
					carry = false;
				}
			} else {
				if (res_bit > 1){
					res_bit = 0;
					carry = true;
				} else {
					carry = false;
				}
			}
			std::cout << a_bit << '\t' << b_bit << '\t' << res_bit << std::endl;
			output[i] = res_bit + '0';
			if (i == 0){
				if (carry){
					output = '1' + output;
				}
				break;
			}
			i--;
		}
		return output;
    }

};

int main(){
	// string a = "1010";
	// string b = "1011";
	string a = "11";
	string b = "1";
	Solution sol;
	string res = sol.addBinary(a, b);
	std::cout << "res: " << res << std::endl;
	
}

