#include <bits/stdc++.h>
using namespace std;

// UNFINISHED

class TopVotedCandidate {
private:
	map<int, pair<int, int>> leading_map; // time, <leading candidate, most recent insert>
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		map<int, int> vote_map;
		const int N = persons.size();
		for (int i = 0; i < N ; i++){
			if (vote_map.find(persons[i]) == vote_map.end())
				vote_map.insert({persons[i], 1});
			else
				vote_map[persons[i]]++;
			
			int leader = max_element(vote_map.begin(), vote_map.end(),
				[](const pair<int,int> &a, const pair<int,int>&b){
					return a.second < b.second;
				})->first;
			leading_map.insert({times[i], make_pair(leader, persons[i])});
		}
		printLeading();
    }
    
    int q(int t) {
		pair<int,int> closest = min_element(leading_map.begin(), leading_map.end(), 
				[=](const pair<int,pair<int,int>> &a, const pair<int,pair<int,int>> &b){
				return abs(a.first - t) < abs(b.first - t);
			})->second;
		// This isn't going to work sadly
		return 69;
    }

	void printLeading(){
		for (pair<int,pair<int,int>> p : leading_map)
			printf("{%i : %i}, ", p.first, p.second.first);
		printf("\n");
	}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */

int main(){
	vector<int> persons = {0, 1, 1, 0, 0, 1, 0};
	vector<int> times = {0, 5, 10, 15, 20, 25, 30};
	TopVotedCandidate sol = TopVotedCandidate(persons, times);
	
	vector<int> tests = {3,12,25,15,24,8};
	for (int t : tests){
		cout << sol.q(t) << endl;
	}
}
