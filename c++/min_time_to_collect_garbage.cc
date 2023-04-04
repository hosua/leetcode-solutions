#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
		travel.push_back(0);
		const int N = garbage.size();
		int m_time, p_time, g_time;
		int m_last, p_last, g_last;
		m_time = p_time = g_time = 0;
		m_last = p_last = g_last = 0;
		for (int i = 0; i < N; i++){
			int travel_time = travel[i];
			string garb = garbage[i];
			for (char ch : garb){
				switch(ch){
					case 'M':
						m_time++;
						m_last = m_time;
						break;
					case 'P':
						p_time++;
						p_last = p_time;
						break;
					case 'G':
						g_time++;
						g_last = g_time;
						break;
				}
			}
			m_time += travel_time;
			p_time += travel_time;
			g_time += travel_time;
		}
		m_time = m_last;
		p_time = p_last;
		g_time = g_last;
		// cout << m_time << " " << p_time << " " << g_time << "\n";
		return m_time + p_time + g_time;
    }
};

int main(){
    Solution sol;
	vector<string> garbage = {"G", "P", "GP", "GG"}; vector<int> travel = {2,4,3};
	int res = sol.garbageCollection(garbage, travel);
	cout << res << "\n";
}
