#include <bits/stdc++.h>
using namespace std;

class Bitset {
	bool flipped;
	int bit_cnt;
	int sz;
	vector<bool> vec;
public:
    Bitset(int size) : bit_cnt(0), flipped(false) {
		sz = size;
       	vec = vector<bool>(sz, 0); 
    }
    
    void fix(int idx) {
		if (!vec[idx])
			bit_cnt++;
       	vec[idx] = 1; 
    }
    
    void unfix(int idx) {
		if (vec[idx])
			bit_cnt--;
       	vec[idx] = 0; 
    }
    
    void flip() {
		flipped = (flipped) ? false : true;
    }
    
    bool all() {
		return bit_cnt == sz;
    }
    
    bool one() {
		return bit_cnt > 0;
    }
    
    int count() {
		return (flipped) ? sz-bit_cnt : bit_cnt;
    }
    
    string toString() {
       	string str;
		for (int i = 0; i < sz; i++){
			bool bit;
			if (!flipped)
				bit = vec[i];
			else
				bit = (vec[i]) ? 0 : 1;

			str += to_string(bit);
		}
		return str;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
int main(){
	Bitset bs(2);

	bs.flip();
	bs.unfix(1);
	cout << bs.all() << endl;
	bs.fix(1);
	bs.fix(1);
	bs.unfix(1);
	cout << bs.all() << endl;
	cout << bs.count() << endl;
	cout << bs.toString() << endl;
	cout << bs.toString() << endl;
	cout << bs.toString() << endl;
	bs.flip();
	cout << bs.toString() << endl;
	cout << bs.count() << endl;
}
