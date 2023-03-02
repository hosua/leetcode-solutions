#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
		const int N = chars.size();
		int i = 0, res = 0;
		while (i < N){
			int count = 1;
			while (i + count < N && chars[i+count] == chars[i])
				count++;
			chars[res++] = chars[i];
			if (count > 1)
				for (char ch : to_string(count))
					chars[res++] = ch;
			i += count;
		}
		return res;
	}
};

int main(){
    Solution sol;
	// vector<char> chars = {'a'};
	vector<char> chars = {'a','a','b','b','c','c','c'};
	// vector<char> chars = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	int res = sol.compress(chars);
	
	cout << "res: " << res << "\n";
	for (int i = 0; i < res; i++)
		cout << chars[i] << "";
	// for (char ch : chars)
	// 	cout << ch;
	cout << "\n";
}
