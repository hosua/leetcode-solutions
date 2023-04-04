#include <bits/stdc++.h>
using namespace std;

unordered_map<char, pair<int,int>> moves = {
	{'L', {-1, 0}}, {'R', {+1, 0}}, 
	{'U', {0, -1}}, {'D', {0, +1}}
};

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
		vector<int> res;
		const int N = s.size();
   		pair<int,int> start = make_pair(startPos[1], startPos[0]);     
		for (int i = 0; i < N; i++){
			bool flag = true;
			pair<int,int> pos = start;
			int valid_moves = 0;
			for (int j = i; j < N; j++){
				char ch = s[j];	
				pair<int,int> mv = moves[ch];
				// cout << "(" << pos.first << "," << pos.second << ")";
				// pos = make_pair(pos.second + mv.second , pos.first + mv.first);
				pos = make_pair(pos.first + mv.first, pos.second + mv.second);
				if (pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= n){
					res.push_back(valid_moves);
					// cout << "\n";
					flag = false;
					break;
				}
				valid_moves++;
			}

			if (flag)
				res.push_back(valid_moves);
		}
		return res;
    }
};

int main(){
    Solution sol;
	int n = 3; vector<int> startPos = {0,1}; string s = "RRDDLU"; // [1,5,4,3,1,0]
	vector<int> res = sol.executeInstructions(n, startPos, s);
	for (int num : res)
		cout << num << " ";
	cout << "\n";
}
