#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	map<int,int> sums;
public:
    int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		if (sums.find(n) != sums.end())
			return sums[n];
		int res = fib(n-1)+fib(n-2);
		sums[n] = res;
		return res;
    }
};

int main(){
	Solution sol;
	cout << sol.fib(5) << endl;
	// for (int i = 0; i < 10; i++){
	// 	cout << sol.fib(i) << endl;
	// }
}
