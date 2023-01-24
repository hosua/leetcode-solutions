#include <bits/stdc++.h>
using namespace std;

// void swap(int a, int b, vector<int>& arr){
// 	int temp = arr[a];
// 	arr[a] = arr[b];
// 	arr[b] = temp;
// }

class Solution {
public:
	// Heap's algorithm
    vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		// pass by reference is important here
		function <void(int,vector<int>&)> rec = 
			[&](int n, vector<int>& arr){
			if (n == 1){
				res.push_back(arr);
				return;
			}
			for (int i = 0; i < n; i++){
				(n % 2 == 0) ? swap(arr[i], arr[n-1]) : swap(arr[0], arr[n-1]);
				rec(n-1, arr);
			}
		
		};
		rec(nums.size(), nums);
		return res;
    }
};

int main(){
    Solution sol;
	// vector<int> nums = {1,2,3};
	vector<int> nums = {5,4,6,2};
	vector<vector<int>> res = sol.permute(nums);
	for (vector<int> list : res){
		for (int num : list)
			cout << num << " ";
		cout << "\n";
	}
}
