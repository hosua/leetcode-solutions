#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:    
	// true if s1 perm of s2
	bool checkInclusion(string s1, string s2) {
		function <bool(int,string&)> rec;
		vector<string> perms;

		rec = [&](int n, string& perm) -> bool {
			if (s2.find(perm) != std::string::npos)
				return true;
			for (int i = 0; i < n; i++){
				(n % 2 == 0) ? swap(perm[i], perm[n-1]) : swap(perm[0], perm[n-1]);
				if (rec(n-1, perm))
					return true;
			}
			return false;
		};


		return rec(s1.size(), s1);
		return false;
    }
};

int main(){
    Solution sol;
	// string s1 = "ab", s2 = "eidbaooo"; // true
	string s1 = "adc", s2 = "dcda";
	cout << sol.checkInclusion(s1, s2) << "\n";
}
