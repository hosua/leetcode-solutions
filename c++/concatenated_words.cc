#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> res;      
		unordered_set<string> s(words.begin(), words.end());

		for (string word : words){
			const size_t N = word.size();
			vector<bool> dp(N+1, false);
			dp[0] = true;
			for (int i = 0; i < N; i++){
				if (not dp[i])
					continue;
				for (int j = i+1; j <= N; j++){
					if (j - i < N and s.count(word.substr(i, j-i)))
						dp[j] = true;
				}
				if (dp[N]){
					res.push_back(word);
					break;
				}
			}	
		}
		return res;
	}

};

int main(){
	Solution sol;
	vector<string> words = { "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
	// Expected output ["catsdogcats","dogcatsdog","ratcatdogcat"]
	vector<string> res = sol.findAllConcatenatedWordsInADict(words);
	for (string word : res)
		cout << word << " ";
	cout << "\n";
}
