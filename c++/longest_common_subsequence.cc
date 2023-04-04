#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

public:
    int longestCommonSubsequence(string a, string b) {
		int m = a.size(), n = b.size();
		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for (int i = 1; i < m+1; i++){
			for (int j = 1; j < n+1; j++){
				// If current chars in string a and b match, then we should move pointers left
				if (a[i-1] == b[j-1])
					dp[i][j] = dp[i-1][j-1] + 1;
				// If they don't match, then we need to check the results from moving both
				// pointers separately, then set the current index to the maximum of both results
				// since we want the longest common subsequence
				else
					dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}
		return dp[m][n];
    }
};

int main(){
    Solution sol;
	string a = "hello", b = "lololol"; // 3
	int res = sol.longestCommonSubsequence(a, b);
	cout << "res: " << res << "\n";
}
