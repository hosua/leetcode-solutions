#include <bits/stdc++.h>
using namespace std;
class Solution {
	set<int> square_set;
public:
    int numSquares(int n) {
    	for (int i = 1; i*i <= n; i++)
			square_set.insert(i*i);

		if (n == *--square_set.end())
			return 1;
		return BFS(n);
    }

	int BFS(int n){
		queue<int> q;
		for (int num : square_set)
			q.push(num);

		int dist = 1;
		while (!q.empty()){
			dist++;
			int breadth = q.size();
			for (int i = 0; i < breadth; i++){
				int v1 = q.front();
				q.pop();
				for (int v2 : square_set){
					int v = v1 + v2;	
					if (v == n)
						return dist;
					else if (v < n)
						q.push(v);	
					else
						break;
				}
			}
		}
		return -1;
	}
};

int main(){
	int n = 12;
	Solution sol;
	cout << sol.numSquares(n);
}
