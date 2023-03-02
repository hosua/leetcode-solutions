#include <bits/stdc++.h>
using namespace std;


// Definitely revisit this problem
class LRUCache {
	int capacity;
	list<int> recent;
	unordered_map<int, pair<int, list<int>::iterator>> mp;
public:
    LRUCache(int capacity) : capacity(capacity) {

	}
    
    int get(int key) {
		auto itr = mp.find(key);
		if (itr == mp.end())
			return -1;

		recent.erase(itr->second.second);
		recent.push_front(key);
		itr->second.second = recent.begin();
		return itr->second.first;
    }
    
    void put(int key, int value) {
		auto itr = mp.find(key);
		if (itr != mp.end())
			recent.erase(itr->second.second);

		recent.push_front(key);
		mp[key] = {value, recent.begin()};
		if (mp.size() > capacity){
			int oldest_key = recent.back();
			recent.pop_back();
			mp.erase(oldest_key);
		}
    }
};

int main(){
	LRUCache lru(2);
	lru.put(1,1);
	lru.put(2,2);
	cout << lru.get(1) << "\n";
	lru.put(3,3);
	cout << lru.get(2) << "\n";
	lru.put(4,4);
	cout << lru.get(1) << "\n";
	cout << lru.get(3) << "\n";
	cout << lru.get(4) << "\n";

}
