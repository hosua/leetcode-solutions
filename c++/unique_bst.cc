#include <bits/stdc++.h>
using namespace std;


// https://en.wikipedia.org/wiki/Catalan_number
class Solution {
	unordered_map<int, int> mp;
public:
    int numTrees(int n) {
		if (n < 2)
			return 1;
		int res = 0;
		for (int i = 1; i <= n; i++){
			int a, b;
			if (mp.find(i-1) == mp.end())
				a = mp[i-1] = numTrees(i-1);
			else 
				a = mp[i-1];

			if (mp.find(n-i) == mp.end())
				b = mp[n-i] = numTrees(n-i);
			else 
				b = mp[n-i];
			res += a * b;
		}
		return res;
    }
};

int main(){
    Solution sol;
	int n = 19;
	int res = sol.numTrees(n);
	cout << res << "\n";
}
