#include <bits/stdc++.h>
using namespace std;

// This solution does not meet time complexity constraints, but still passes test cases
class RandomizedSet {
private:
	set<int> val_set;
public:
	RandomizedSet() {
		srand(time(0));
	}

	bool insert(int val) {
		if (val_set.find(val) != val_set.end())
			return false;
		val_set.insert(val);
		return true;
	}

	bool remove(int val) {
		if (val_set.find(val) == val_set.end())
			return false;
		val_set.erase(val);
		return true;
	}

	int getRandom() {
		int sz = val_set.size();
		int rng = (rand() % sz);
		set<int>::iterator itr = val_set.begin();
		advance(itr, rng);
		return *itr;
	}
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
	RandomizedSet r_set;
	for (int i = 0; i < 5; i++){
		r_set.insert(i);	
	}

	for (int i = 0; i < 10; i++){
		cout << r_set.getRandom() << endl;
	}
}
