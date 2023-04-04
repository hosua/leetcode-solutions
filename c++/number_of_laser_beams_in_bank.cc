#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
		const int N = bank.size();
		vector<int> device_counts(N, 0);        
		for (int i = 0; i < N; i++)
			for (char ch : bank[i])
				if (ch == '1')
					device_counts[i]++;
		for (int i = device_counts.size()-1; i >= 0; i--)
			if (device_counts[i] == 0)
				device_counts.erase(device_counts.begin()+i);
		int res = 0;
		for (int i = 1; i < device_counts.size(); i++)
			res += (device_counts[i] * device_counts[i-1]);
		return res;
    }
};

int main(){
    Solution sol;
	vector<string> bank = {"011001","000000","010100","001000"}; // 8
	int res = sol.numberOfBeams(bank);
	cout << res << "\n";
}
