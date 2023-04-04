#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
		const int N = s.size();
 		int res = 1; // There will always be at least 1 partition
		unordered_set<char> st;
		int i = 0;
		while (i < N){
			char ch = s[i++];
			if (st.find(ch) != st.end()){ // Found duplicate letter in substring, start new partition
				i--; // Go back an index to include the current letter in the partition
				res++; 
				st.clear();
			} else {
				st.insert(ch);
			}
		}

		return res;
    }
};

int main(){
	// string s = "abacaba"; // 4
	string s = "hdklqkcssgxlvehva";
    Solution sol;
	int res = sol.partitionString(s);
	cout << res << "\n";
}
