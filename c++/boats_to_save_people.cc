#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
		const int N = people.size();
		sort(people.begin(), people.end());
		int res = 0;
		int left = 0, right = N-1;
		
		int i = 0;
		vector<pair<int,int>> boats;

		while (left <= right)
			if (people[left] + people[right] <= limit)
				boats.push_back(make_pair(people[left++], people[right--]));
			else
				boats.push_back(make_pair(people[right--], 0));

		return boats.size();
    }
};

int main(){
    Solution sol;
	vector<int> people = {3,2,2,1}; int limit = 3; // 3
	// vector<int> people = {3,5,3,4}; int limit = 5; // 4
	int res = sol.numRescueBoats(people, limit);
	cout << res << "\n";
}
