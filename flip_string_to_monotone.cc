#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
public:
	int minFlipsMonoIncr(string s) {
		int res = 0;
		const int N = s.size();
		int one_count = 0;
		for (char ch : s)
			(ch == '0') ? res = min(res+1, one_count) : one_count++;
		return res;
    }
};

void test(){
	Solution sol;
	vector<string> input = {"00110","010110","00011000","11011"};
	vector<int> expected = {1,2,2,1};
	assert(input.size() == expected.size() and "Error: input size does not match expected size\n");
	const int N = input.size();
	for (int i = 0; i < N; i++){
		int output;
		if ((output = sol.minFlipsMonoIncr(input[i])) != expected[i]){
			string err_msg = "Error: Test case " + to_string(i) + "\n" +
				"Input: \"" + input[i] + "\"\n" + 
				"Your output: " + to_string(output) + "\n" +
				"Expected output: " + to_string(expected[i]) + "\n";
			cout << err_msg;
			exit(1);
		}
	}
}

int main(){
    Solution sol;
	test();
}
