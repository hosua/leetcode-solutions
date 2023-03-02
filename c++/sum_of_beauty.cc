#include <bits/stdc++.h>
using namespace std;

// TLE CUZ I FUCKING SUCK
class Solution {
public:
    int beautySum(string s) {
       	vector<string> substrings = getSubstrings(s); 
		int sum = 0;
		for (string sub : substrings){
			int most = INT_MIN, least = INT_MAX;
			map<char, int> freq_map;
			for (char ch : sub){
				if (freq_map.find(ch) == freq_map.end())
					freq_map.insert({ch, 1});
				else
					freq_map[ch]++;
			}

			for (pair<char, int> p : freq_map){
				if (p.second > most)
					most = p.second;
				if (p.second < least)
					least = p.second;
			}
			int beauty = most-least;
			sum += beauty;
		}
		return sum;
    }

	vector<string> getSubstrings(string s){
		const size_t N = s.size();
		vector<string> substrings;
		for (int len = 1; len <= N; len++){
			for (int i = 0; i <= N-len; i++){
				int j = len+i-1;
				string sub;
				for (int k = i; k <= j; k++)
					sub += s[k];
				substrings.push_back(sub);
			}
		}
		return substrings;
	}
};
int main(){
	Solution sol;
	cout << sol.beautySum("aabcbaa") << endl;
}
