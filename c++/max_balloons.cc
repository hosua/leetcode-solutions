#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
   		map<char, int> freq_map;
		for (char ch : text){
			if (freq_map.find(ch) == freq_map.end())
				freq_map.insert( {ch, 1} );
			else
				freq_map[ch]++;
		}
		string s = "balon";
		vector<int> v;
		for (char ch : s){
			if (ch == 'l' || ch == 'o')
				freq_map[ch] /= 2;
			if (freq_map.find(ch) == freq_map.end())
				return false;
			else
				v.push_back(freq_map[ch]);	
		}
		return *min_element(v.begin(), v.end());
    }
};

int main(){
	Solution sol;
	string s = "loonbalxballpoon";
	cout << sol.maxNumberOfBalloons(s);
	
}
