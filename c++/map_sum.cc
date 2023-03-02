#include <bits/stdc++.h>
using namespace std;

class MapSum {
private:
	unordered_map<string,int> mp;
public:
    MapSum(){
    }
    
    void insert(string key, int val) {
		mp[key] = val;
    }
    
    int sum(string prefix) {
		int sum = 0;
		for (unordered_map<string,int>::iterator itr = mp.begin(); itr != mp.end(); itr++){
			string key = itr->first;
			int val = itr->second;
			if (key.rfind(prefix, 0) == 0)
				sum += val;
		}
		return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(){
    MapSum ms;
	ms.insert("apple",3);
	cout << ms.sum("app") << "\n"; // 3
	ms.insert("app", 2);
	ms.insert("apple",2);
	cout << ms.sum("ap") << "\n"; // 4
}
