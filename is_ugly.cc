#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isUgly(int n){
		if (n == 1)
			return true;
		int m = n;
		if (n % 5 == 0)
			n /= 5;
		if (n % 3 == 0)
			n /= 3;
		if (n % 2 == 0)
			n /= 2;
		if (m == n)
			return false;
		return isUgly(n);
	}
};
int main(){
	Solution sol;
	cout << sol.isUgly(6);
}
