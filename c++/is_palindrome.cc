#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
		string str;
		for (char ch : s)
			if (isalnum(ch))
				str += tolower(ch);
       	int left = 0, right;
		(str.size()-1 > 0) ? right = str.size()-1 : right = 0;
		while (left <= right){
			if (str[left] != str[right])
				return false;
			left++; right--;
		}
		return true;
    }
};

int main(){
	string s = "A man, a plan, a canal: Panama";
	Solution sol;
	cout << sol.isPalindrome(s);

}
