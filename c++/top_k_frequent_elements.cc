#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
 		vector<int> res;       
		map<int, int> freq_map; // <val, freq>
		map<int, vector<int>> counts_map; // <freq, vals>
		sort(nums.begin(), nums.end());
		for (int num : nums){
			if (freq_map.find(num) == freq_map.end())
				freq_map.insert( {num, 1} );
			else
				freq_map[num]++;
		}
		// our largest frequency can be at most the size of the nums vector
		int bucket[nums.size()];
		for (auto itr = freq_map.begin(); itr != freq_map.end(); itr++){
			int val = itr->first, freq = itr->second;
			if (counts_map.find(freq) == counts_map.end())
				counts_map.insert( {freq, vector<int> {val}} );
			else
				counts_map[freq].push_back(val);
		}
		int ki = 0;
		// iterate in reverse to get most frequent inputs first
		for (auto itr = counts_map.rbegin(); itr != counts_map.rend(); itr++){
			vector<int> val_list = itr->second;
			for (int num : val_list){
				if (ki == k)
					return res;
				res.push_back(num);
				ki++;
			}
		}
		return res;
    }
};

int main(){
	Solution sol;
	// vector<int> v = {1, 2}; int k = 2;
	vector<int> v = {1, 1, 1, 2, 2, 3}; int k = 2;
	vector<int> res = sol.topKFrequent(v, k);
	for (int num : res)
		cout << num << " ";
	cout << endl;
}
