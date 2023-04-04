#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		const int N = haystack.size();
		int i = 0;
		while (i < N){
			if (haystack[i] == needle[0]){
				int j = i;
				int k = 0;
				while (k < needle.size() && haystack[j++] == needle[k++]);
				if (k == needle.size())
					return i;
			}
			i++;
		}
		return -1;
    }
};

int main(){
    Solution sol;
	// string haystack = "sadbutsad", needle = "sad"; // 0
	// string haystack = "leetcode", needle = "leeto"; // -1
	string haystack = "a", needle = "a";	 // 0 
	// string haystack = "abc", needle = "c"; // 2
	int res = sol.strStr(haystack, needle);
	cout << res << "\n";
}
