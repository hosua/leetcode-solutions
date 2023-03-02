#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
 		int left = 0;
		int right = s.size()-1;

		while (left <= right){
			char temp = s[left];
			s[left] = s[right];
			s[right] = temp;
			left++;
			right--;
		}
    }
};

int main(){
	Solution sol;
	vector<char> s = { 'h', 'e', 'l', 'l', 'o' };
	sol.reverseString(s);
	for (char ch : s){
		cout << ch;
	}
}
