#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
		const int N = boxes.size();
		vector<int> res(N,0);        
		set<int> s; // store index where bits in string are set
		for (int i = 0; i < N; i++)
			if (boxes[i] == '1')
				s.insert(i);

		for (int i = 0; i < N; i++)
			for (int j : s)
				if (i != j)
					res[i] += abs(j-i);
		return res;
    }
};

int main(){
    Solution sol;
	string boxes = "110";
	vector<int> res = sol.minOperations(boxes);
	for (int r : res)
		cout << r << " ";
	cout << "\n";
}
