#include <bits/stdc++.h>
using namespace std;
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);
int guess_check(int num, int target);

class Solution {
public:
    int guessNumber(int n) {
	}
};

int guess_check(int num, int target){
	if (num > target)
		return -1;
	else if (num < target)
		return 1;
	else 
		return 0;
}

int main(){
	Solution sol;
	sol.guessNumber(10);

}
