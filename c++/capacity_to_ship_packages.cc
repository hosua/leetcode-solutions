#include <bits/stdc++.h>
using namespace std;

// This shit is too hard

// If my intuition were able to solve this problem, this would be the thought process.

// 1) Create a function that actually checks if a given capacity actually works within
// the input number of days ( the feasible() function )

// 2) As for finding the actual capacity, we need to define the boundaries of what is possible.
	// For the minimal capacity, we can not have a number lower than the maximal weight.
	// (this is easier to see when we consider a weights array of [1,1,1,1,1,6],
	// pretend that we have days = 2, we can fit all the 1's using a capacity of 5, BUT, we 
	// absolutely require a minimum of 6 to fit weight[i] = 6. This will always hold
	// no matter what and hopefully, this example is clear enough to be obvious now. )
	
// 3) Now ask yourself, what is the maximum capacity?
	// To find this value, we should consider the most extreme case.
	// Let's say we have the weights array {1,2,3,4,5} with days = 1.
	// Since we need to get all of our packages in one day, the only valid capacity here must be 
	// the sum of all weights! Therefore, this must be our absolute maximum for the most extreme
	// case.
	
// 4) Now that we have a range that we can work with, the naive thing to do would probably be
// to iterate through all possibilities in our range. But wait, our range is sorted! More specifically,
// the possible capacities in our range we defined are sorted!
 
// 5) Since our capacity range is sorted, we can use binary search to divide and conquer for our solution
// to arrive at our capacity. When divising our binary search, we should have a left/low and right/high pointer
// so that we can find our middle of our current search.

// 6) Use the feasible() function that we defined earlier to determine if we should check a higher or lower 
// capacity. 
// In our binary search: 
	// * if the capacity is feasible, then there must exist a better capacity 
	// towards the right half of our capacity range (higher capacity is better, since 
	// we are trying to maximize it), 
	// * if the capacity is not feasible, then we must have overstepped our capacity. We should
	// search the left half of our capacity range for our answer.
	// * if (left/low == right/high), we have our answer. Return left || right || low || high.


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
		int res;
		// our capacity can not be less than the maximum weight in weights.
    	int max_wt = *max_element(weights.begin(), weights.end());    
		// our capacity must also not exceed the total sum of the weights.
		int total_wt = accumulate(weights.begin(), weights.end(), 0);
		return binarySearch(max_wt, total_wt, weights, days);
    }
	
	bool feasible(int capacity, vector<int> weights, int days){
		int num_days = 1, curr_wt = 0;
		for (int wt : weights){
			if (wt + curr_wt > capacity){
				num_days++;
				curr_wt = wt;
			} else {
				curr_wt += wt;
			}
		}
		return (num_days <= days);
	}

	int binarySearch(int left, int right, vector<int> weights, int days){
		// safe binary search (unnecessary for this problem, but I never knew about it)
		// int mid = left + ((right - left) / 2); 
		// here we can just use the more intuitive version:
		if (left == right)
			return left;
		int mid = (left+right)/2;
		// If the capacity is feasible, then a better answer exists to the left
		if (feasible(mid, weights, days)){
			return binarySearch(left, mid, weights, days);
		// Otherwise, it must be less than the capacity we checked	
		} else {
			return binarySearch(mid+1, right, weights, days);
		}
	}
};

int main(){
    Solution sol;
	vector<int> weights = {1,2,3,4,5,6,7,8,9,10}; int days = 5; // 15
	int res = sol.shipWithinDays(weights, days);
	cout << res << "\n";
}
