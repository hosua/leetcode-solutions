#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int totalFruit(vector<int>& fruits) {
		const int N = fruits.size();
		int left, right;
		for (left = 0, right = 0; right < N; right++){
			baskets[fruits[right]]++;
			if (tooManyFruits()){
				baskets[fruits[left]]--;
				if (baskets[fruits[left]] == 0)
					baskets.erase(fruits[left]);
				left++;
			}
		}
		return right - left;
    }

private:
	unordered_map<int, int> baskets;
	bool tooManyFruits(){ return (baskets.size() > 2); }
};

int main(){
    Solution sol;
	vector<int> fruits = {1,2,1};
	int res = sol.totalFruit(fruits);
	cout << res << "\n";
}
