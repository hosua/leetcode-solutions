#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	vector<vector<int>> combine(int n, int k) {
   		vector<vector<int>> res;	
		function <void(int,vector<int>)> rec;
		rec = [&](int i, vector<int> vec){
			if (vec.size() == k){
				res.push_back(vec);
				return;
			}

			for (int j = i; j <= n; j++){
				if (j != i){
					vec.push_back(j);
					rec(j, vec);
					vec.pop_back();
				}
			}
		};
		rec(0, {});
		return res;
    }
};

int main(){
    Solution sol;
	int n = 4, k = 2;
	vector<vector<int>> res = sol.combine(n, k);
	for (vector<int> r : res){
		for (int num : r)
			cout << num << " ";
		cout << "\n";
	}
}
