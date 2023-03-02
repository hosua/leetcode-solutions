#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
		const int N = piles.size();
		// We can never take 0 hours to eat any bananas.
		int left = 1;
		// The maximum number of hours we can possibly take is the maximal element in piles.
		// It will must never take us longer than 1 hour to eat 1 banana.
		int right = *max_element(piles.begin(), piles.end());
		// cout << "right: " << right << "\n";
		return binarySearch(left, right, piles, h);	
    }

private:
	// bph = bananas per hour
	bool canEatBananas(int bph, vector<int> piles, int h){
		int hour = 0;
		for (int pile : piles){
			// TODO: I got tripped up here. This is what I could not figure out.
			// I'm pretty stupid honestly.
			hour += pile/bph;
			if (pile % bph) // If any bananas remain in the pile, we need another hour to finish them.
				hour++;
		}	
		return (hour <= h);
	}

	int binarySearch(int left, int right, vector<int> piles, int h){
		if (left == right)
			return left;
		int mid = left+(right-left)/2;
		// If we can eat the bananas in k (mid) bananas per hour, then there must exist
		// a better k towards the left of our range, so search the left half of our range.
		if (canEatBananas(mid, piles, h))
			return binarySearch(left, mid, piles, h);	
		// If we can't eat them in k, then we tried a k that was too low. We need to try
		// a higher k, so check the right half of our range.
		else
			return binarySearch(mid+1, right, piles, h);	
	}
};

int main(){
    Solution sol;
	// vector<int> piles = {3,6,7,11}; int h = 8; // 4
	// vector<int> piles = {30,11,23,4,20}; int h = 5; // 30
	// vector<int> piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
	// int h = 823855818; // 14
	vector<int> piles = {312884470};
	int h = 968709470;
	// cout << INT_MAX << "\t" << h << "\n";
	int res = sol.minEatingSpeed(piles, h);
	cout << res << "\n";
}
