#include <iostream>
using std::string;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int longest = 0;
		int curr_len = 0;
		int i = 0;
		std::string curr_str;
		while (true){
			char ch = s[i];
			if (curr_str.find(ch) != std::string::npos){
				curr_len = 0;	
				curr_str = "";
			} else {
				curr_str.append(string(1, ch));
				curr_len++;
			}
			if (longest < curr_len){
				longest = curr_len;
			}
			if (i == s.length())
				break;
			i++;
		}
		return longest;
    }
};

int main(){
	Solution sol;
	// std::string s = "abcabcbb";
	std::string s = "pwwkew";
	// std::string s = "aab";
	int res = sol.lengthOfLongestSubstring(s);
	std::cout << res << std::endl;
}
