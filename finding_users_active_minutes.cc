#include <bits/stdc++.h>
using namespace std;

class Solution {
	int K;
	unordered_map<int,unordered_set<int>> uam;
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
		K = k;
		vector<int> res(K, 0);

		for (vector<int> log : logs){
			int id = log[0], time = log[1];
			cout << id << " " << time << endl;
			if (uam.find(id) == uam.end()){
				unordered_set<int> s;
				s.insert(time);
				uam.insert(make_pair(id, s));
			} else
				uam[id].insert(time);
		}

		for (pair<int,unordered_set<int>> p : uam){
			int id = p.first;
			unordered_set<int> times = p.second;
			cout << id << ": {";
			for (int time : times)
				cout << time << ",";
			cout << "}\n";
		}

		for (pair<int,unordered_set<int>> p : uam){
			int id = p.first;
			int actions = uam[id].size();	
			if (actions)
				res[actions-1]++;
		}
		return res;
    }
};

int main(){
	Solution sol;
	// vector<vector<int>> logs = {{0,5},{1,2},{0,2},{0,5},{1,3}};
	// int k = 5; // Output: [0,2,0,0,0]
	// vector<vector<int>> logs = {{1,1},{2,2},{2,3}};
	// int k = 4; // Output: [1,1,0,0]
	// vector<vector<int>> logs = {{305589003,4136},{305589004,4139},{305589004,4141},{305589004,4137},{305589001,4139},{305589001,4139}};
	// int k = 6; // Output: [0,0,0,0,0,0]
	vector<vector<int>> logs = {{305589003,4136},{305589004,4139},{305589004,4141},{305589004,4137},{305589001,4139},{305589001,4139}};
	int k = 6; // Output: [2,0,1,0,0,0];

	vector<int> res = sol.findingUsersActiveMinutes(logs, k);
	for (int num : res)
		cout << num << " ";
	cout << endl;
}
