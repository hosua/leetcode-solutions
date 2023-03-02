#include <bits/stdc++.h>
using namespace std;

// Couldn't get this one again. 
// It really helps to draw out the graph to really understand the solution.
class Solution {
	int N;
public:
    int maxProfit(vector<int>& prices) {
		N = prices.size();
		int min_price = INT_MAX;
		int max_profit = INT_MIN;

		for (int price : prices){
			if (price < min_price)
				min_price = price;
			else if (price - min_price > max_profit)
				max_profit = price - min_price;
		}
		return (max_profit == INT_MIN) ? 0 : max_profit;	
    }

private:
	bool inBounds(int n){
		return (n >= 0 && n < N);
	}
};

void testAll(){
	vector<vector<int>> tests = {
		{7,1,5,3,6,4}, // 5
		{7,6,4,3,1}, // 0 
		{1,2}, // 1
		{3,2,6,5,0,3}, // 4
		{1,2,4,2,5,7,2,4,9,0,9} // 9
	};
	vector<int> valid = {5,0,1,4,9};
	const int T = tests.size(), V = valid.size();
	assert(T == V && "Error: tests and valid vectors must be of equal size");
	Solution sol;
	cout << "-----------------\n";
	for (int i = 0; i < T; i++){
		cout << "Running test: " << i+1 << "\n";
		int res = sol.maxProfit(tests[i]);
		cout << "Got: " << res << "\texpected: " << valid[i] << "\n";
		assert(res == valid[i] && "Error: test did not match expected answer");
		cout << "-----------------\n";
	}
}

int main(){
    Solution sol;
	// vector<int> v = {7,1,5,3,6,4}; // 5
	// vector<int> v = {7,6,4,3,1}; // 0 
	// vector<int> v = {1,2}; // 1
	// vector<int> v =  {3,2,6,5,0,3}; // 4
	// int res = sol.maxProfit(v);
	// cout << res << "\n";
	testAll();
}
