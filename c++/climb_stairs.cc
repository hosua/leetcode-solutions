#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	map<int, int> cache;
public:
    int climbStairs(int n) {
		return fib(n+1);
    }

	int fib(int n){
		if (cache.find(n) != cache.end()){
			return cache[n];
		}
		if (n <= 1){
			return n;
		}
		int res = fib(n-1)+fib(n-2);
		cache[n] = res;
		return res;
	}
};


int main(){
	Solution sol;
	cout << sol.climbStairs(5);
}
