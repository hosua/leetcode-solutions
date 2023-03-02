#include <bits/stdc++.h>
using namespace std;

// Not working but idc anymore
class Solution {
private:
	map<char,int> mp;
public:
	bool isAlienSorted(vector<string>& words, string order){
		for (int i = 0; i < order.size(); i++)
			mp[order[i]] = i;
		vector<string> sorted = words;
		sort(sorted.begin(), sorted.end(), [](string a, string b){
			int i = 0;
			while (a[i] == b[i]){
				i++;
			}
			return a[i] < b[i];
		});
		return (sorted == words);
	}
};

int main(){
	Solution sol;
	// vector<string> words = {"hello","leetcode"};
	// string order = "hlabcdefgijkmnopqrstuvwxyz"; // true
	
	vector<string> words = {"ubg","kwh"};
	string order = "qcipyamwvdjtesbghlorufnkzx"; // true
	bool res = sol.isAlienSorted(words, order);
	cout << res << "\n";
}
