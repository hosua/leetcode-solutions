#include <bits/stdc++.h>
using namespace std;

vector<string> getAllSubsets(string str){
	const int N = str.size();
	vector<string> subsets(1<<N);

	for (int i = 0; i < (1<<N); i++){
		for (int j = 0; j < (1<<N); j++){
			if (i & (1<<j))
				subsets[i].push_back(str[j]);
		}
	}
	return subsets;
}

int main(){
	// vector<int> nums = {1,2,3};
	string str = "Josh";
	vector<string> subsets = getAllSubsets(str);

	for (string s : subsets)
		cout << s << " ";
	cout << "\n";
}
