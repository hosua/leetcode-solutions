#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		map<string, vector<string>> ana_map;
       	for (string str : strs){
			string sorted = str;
			sort(sorted.begin(), sorted.end());
			if (ana_map.find(sorted) == ana_map.end())
				ana_map.insert( {sorted, vector<string>{str}} );
			else
				ana_map[sorted].push_back(str);
		} 

		for (auto itr = ana_map.begin(); itr != ana_map.end(); itr++)
			res.push_back(itr->second);

		return res;
    }
};
