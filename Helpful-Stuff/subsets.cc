#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getAllSubsets(vector<int> arr){
	const int N = arr.size();
	vector<vector<int>> subsets(1<<N);

	for (int i = 0; i < (1<<N); i++){
		for (int j = 0; j < (1<<N); j++){
			if (i & (1<<j))
				subsets[i].push_back(arr[j]);
		}
	}
	return subsets;
}

int main(){
	vector<int> nums = {1,2,3};
	vector<vector<int>> subsets = getAllSubsets(nums);

	for (vector<int> sub : subsets){
		cout << "{ ";
		for (int num : sub){
			cout << num << " ";
		}	
		cout << "}\n";
	}
}
