#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	void merge(vector<int>& a, int m, vector<int>& b, int n) {
	}
};

int main(){
	Solution sol;
	vector<int> a = {1,2,3,0,0,0}, b = {4,5,6};
	int m = 3, n = 3;
	sol.merge(a, m, b, n);
	for (int num : a)
		cout << num << " ";
	cout << endl;
}
