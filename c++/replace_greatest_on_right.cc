#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
    	for (int i = 0; i < arr.size()-1; i++){
			vector<int> sub_vec(arr.begin()+i+1, arr.end());
			arr[i] = *max_element(sub_vec.begin(), sub_vec.end());
		} 
		arr[arr.size()-1] = -1;
		return arr;
    }
};

int main(){
	Solution sol;
	vector<int> v = {17, 18, 5, 4, 6, 1};
	vector<int> res = sol.replaceElements(v);
	cout << endl;
	for (int num : res){
		cout << num << endl;
	}
}
