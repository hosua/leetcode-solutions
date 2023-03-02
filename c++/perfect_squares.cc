#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numSquares(int n){
		set<int> square_set;
		for (int i = 1; (i * i) <= n; i++)
			square_set.insert(i*i);

		if (*(--square_set.end()) == n)
			return 1;

		return BFS(square_set, n);
	}

	int BFS(set<int> square_set, int n){
		queue<int> q;
		for (int sq : square_set)
			q.push(sq);

		int dist = 1;
		while (!q.empty()){
			dist++;	

			int width = q.size();
			for (int i = 0; i < width; i++){
				int val = q.front();
				for (int sq : square_set){
					if (val + sq == n)
						return dist;	

					if (val + sq < n)
						q.push(val + sq);
					else if (val + sq > n)
						break;
				}
				q.pop();
			}
		}
		return -1;
	}
	/*
    int numSquares(int n) { // DP solution
		vector<int> dp(n+1, n);        
		dp[0] = 0;
		for (int i = 2; i <= n; i++){
			for (int j = 1; j*j <= i; j++){
				dp[i] = min(dp[i], dp[i - j*j] + 1);
				cout << dp[i] << endl;
			}
		}
		return dp[n];
    }
	*/
};

int main(){
	Solution sol;
	cout << sol.numSquares(4);
}
