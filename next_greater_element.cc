#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		res.resize(nums1.size(), -1);
		for (int i = 0; i < nums1.size(); i++){
			int j = 0;
			while (nums2[j++] != nums1[i]);
			for ( ; j < nums2.size(); j++){
				if (nums2[j] > nums1[i]){
					res[i] = nums2[j];
					break;
				}
			}	
		}
		return res;
	}
};

int main(){
	vector<int> a = {4,1,2}, b = {1,3,4,2};
	Solution sol;
	auto res = sol.nextGreaterElement(a, b);
	for (int num : res){
		cout << num << " ";
	}
}
