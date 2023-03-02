#include <bits/stdc++.h>
using namespace std;

#define MAP_SIZE 1000
class MyHashMap {
private:
	vector<vector<pair<int,int>>> mp;
public:
    MyHashMap() : mp(vector<vector<pair<int,int>>>(MAP_SIZE)){}
    
    void put(int key, int value) {
       	int i = key % MAP_SIZE; 
		pair<int,int> new_pair = make_pair(key,value);
		vector<pair<int,int>>::iterator itr = find_if(mp[i].begin(), mp[i].end(), 
			[&](const pair<int,int>& p){ return key == p.first; });
		if (itr == mp[i].end())
			mp[i].push_back(new_pair);
		else
			itr->second = value;
    }
    
    int get(int key) {
       	int i = key % MAP_SIZE; 
		vector<pair<int,int>>::iterator itr = find_if(mp[i].begin(), mp[i].end(), 
			[&](const pair<int,int>& p){ return key == p.first; });
		return (itr == mp[i].end()) ? -1 : itr->second;
    }
    
    void remove(int key) {
       	int i = key % MAP_SIZE; 
		vector<pair<int,int>>::iterator itr = find_if(mp[i].begin(), mp[i].end(), 
			[&](const pair<int,int>& p){ return key == p.first; });
		
		if (itr != mp[i].end())
			mp[i].erase(std::remove(mp[i].begin(), mp[i].end(), *itr), mp[i].end());
    }
};

int main(){

}
