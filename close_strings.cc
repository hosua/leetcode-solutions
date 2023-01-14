#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool closeStrings(string word1, string word2) {
		if (word1.size() != word2.size())
			return false;
		string a = word1, b = word2;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a == b)
			return true;
		map<char, int> a_freq, b_freq;
		for (char ch : word1){
			if (a_freq.find(ch) == a_freq.end())
				a_freq.insert({ch, 1});
			else
				a_freq[ch]++;
		}
		for (char ch : word2){
			if (a_freq.find(ch) == a_freq.end())
				return false;
			if (b_freq.find(ch) == b_freq.end())
				b_freq.insert({ch, 1});
			else
				b_freq[ch]++;
		}
		vector<int> a_vec, b_vec;
		for (pair<char, int> p : a_freq)
			a_vec.push_back(p.second);
		for (pair<char, int> p : b_freq)
			b_vec.push_back(p.second);
		sort(a_vec.begin(), a_vec.end());
		sort(b_vec.begin(), b_vec.end());
		return (a_vec == b_vec);
	}
};

int main(){
	string a="uau", b="ssx";
	Solution sol;
	cout << sol.closeStrings(a, b) << "\n"; 
}
