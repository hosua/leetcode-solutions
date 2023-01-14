#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
		const int N = pref.size();
		vector<int> res(1, pref[0]);
		for (int i = 0; i < N-1; i++)
			res.push_back(pref[i]^pref[i+1]);
		return res;
    }
};

int main(){
	Solution sol;
	vector<int> pref = {5,2,0,3,1};
	vector<int> res = sol.findArray(pref);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
