#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
		const int N = queries.size();
		vector<int> res;        
		vector<int> vec;
		for (int i = 1; i <= m; i++)
			vec.push_back(i);
		
		for (int i = 0; i < N; i++){
			int query = queries[i];
			int idx = distance(vec.begin(), find(vec.begin(), vec.end(), query));
			res.push_back(idx);
			vec.erase(remove(vec.begin(), vec.end(), query), vec.end());
			vec.insert(vec.begin(), query);
		}
		return res;
    }
};

int main(){
    Solution sol;
	vector<int> queries = {3,1,2,1}; int m = 5;
	vector<int> res = sol.processQueries(queries, m);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
