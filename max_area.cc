#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

	// Two pointers, greedy
	int maxArea(vector<int>& height) {
		int max_area = INT_MIN;
		const int N = height.size();
		int left = 0, right = N-1;
		while (left < right){
			int area = min(height[left], height[right]) * (right-left);	
			max_area = max(max_area, area);
			(height[left] > height[right]) ? right-- : left++; // keep the highest height at any given iteration
		}
		return max_area;
	}

	// TLE, brute force
	// int maxArea(vector<int>& height) {
    // 	int max_area = INT_MIN;
	// 	const int N = height.size();
	// 	for (int i = 0; i < N; i++){
	// 		for (int j = i+1; j < N; j++){
	// 			int area = abs(i-j) * min(height[i], height[j]);
	// 			max_area = max(max_area, area);
	// 		}
	// 	}
	// 	return max_area;
    // }
};

int main(){
    Solution sol;
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	cout << sol.maxArea(height) << "\n";
}
