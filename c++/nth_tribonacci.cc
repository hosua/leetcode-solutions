#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	map<int,int> mp;
public:
	int tribonacci(int n) {
		if (n == 0)
			return 0;
		else if (n == 1 or n == 2)
			return 1;
		if (mp.find(n) != mp.end())
			return mp[n];

		return mp[n] = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
    }
};

int main(){
    Solution sol;
	int res = sol.tribonacci(25);
	cout << res << "\n";
}
