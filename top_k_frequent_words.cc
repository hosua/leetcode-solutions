#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
		vector<string> res;
		map<string, int> freq_map; // <word, freq>
		map<int, vector<string>> counts_map; // <freq, words>
		
		for (string word : words){
			if (freq_map.find(word) == freq_map.end())
				freq_map.insert( {word, 1} );
			else
				freq_map[word]++;
		}

		for (auto itr = freq_map.begin(); itr != freq_map.end(); itr++){
			string word = itr->first;
			int freq = itr->second;

			if (counts_map.find(freq) == counts_map.end())
				counts_map.insert( {freq, vector<string> {word}} );
			else
				counts_map[freq].push_back(word);
		}

		int ki = 0;
		for (auto itr = counts_map.rbegin(); itr != counts_map.rend(); itr++){
			vector<string> words = itr->second;
			for (string word : words){
				if (ki == k)
					return res;
				res.push_back(word);
				ki++;
			}
		}

       	return res; 
    }
};

int main(){
	Solution sol;
	vector<string> words = {"i","love","leetcode","i","love","coding"};
	vector<string> res = sol.topKFrequent(words, 2);
	for (string word : res){
		cout << word << endl;
	}
}
