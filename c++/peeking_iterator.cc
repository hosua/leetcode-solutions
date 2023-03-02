#include <bits/stdc++.h>
using namespace std;

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */

class Iterator {
	struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);

	// Returns the next element in the iteration.
	int next();

	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	   	if ((has_nxt = Iterator::hasNext()))
			nxt = Iterator::next();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return nxt;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int curr_nxt = nxt;
		if ((has_nxt = Iterator::hasNext())){
			nxt = Iterator::next();
		}
		return curr_nxt;
	}
	
	bool hasNext() const {
	   	return has_nxt;
	}

private:
	int nxt;
	bool has_nxt;
};


int main(){

}
