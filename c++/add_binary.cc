#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
		string res;
		if (a.length() < b.length())
			swap(a,b);
		const int N = a.size();
		// Pad zeros
		b.insert(b.begin(), N-b.size(), '0');

		bool carry = false;		
		for (int i = N-1; i >= 0; i--){
			int m = a[i]-'0';
			int n = b[i]-'0';
			if (carry){
				if (m+n+carry == 3){
					carry = true;
					res.insert(res.begin(), '1');
				} else if (m+n+carry == 2){
					carry = true;
					res.insert(res.begin(), '0');
				} else { // if m+n+carry == 1 (it cannot by 0 here because of carry)
					res.insert(res.begin(), '1');
					carry = false;
				}
			} else {
				if (m+n == 2){
					carry = true;
					res.insert(res.begin(), '0');
				} else if (m+n == 1)
					res.insert(res.begin(), '1');
				else
					res.insert(res.begin(), '0');
			}
		}

		if (carry)
			res.insert(res.begin(), '1');
		return res;
    }
};

int main(){
	// string a = "1010";
	// string b = "1011";
	// string a = "11";
	// string b = "1";

	string a = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
	string b = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
	Solution sol;
	string res = sol.addBinary(a, b);
	std::cout << "res: " << res << std::endl;
	
}

