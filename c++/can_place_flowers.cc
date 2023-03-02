#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.push_back(0);
		for (int i = 1; i < flowerbed.size()-1; i++){
			if (!flowerbed[i-1] && !flowerbed[i+1] && !flowerbed[i]){
				flowerbed[i] = 1;
				n--;
			}
		}

		return (n <= 0);
	}
};
int main(){
	// vector<int> flowerbed = {1,0,1,0,1,0,1};
	// vector<int> flowerbed = {1,0,1,0,0};
	// vector<int> flowerbed = {0,0,0,0,1};
	// vector<int> flowerbed = {1};
	vector<int> flowerbed = {0, 0, 1, 1, 0, 0};
	int n = 2;
	Solution sol;
	cout << sol.canPlaceFlowers(flowerbed, n);
}
