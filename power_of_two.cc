#include <iostream>
#include <bitset>


class Solution {
	public:
		// All powers of two have only one bit, its MSB, set.
		bool isPowerOfTwo(int n) {
			int set_bits = 0;
			if (n < 0) 
				return false;
			for ( ; n; n >>= 1){
				if ((n & 1) == 1)
					set_bits++;
			}
			if (set_bits == 1)
				return true;
			return false;
		}
};

int main(){
	Solution sol;
	for (int i = 0; i < 20; i++){
		bool res = sol.isPowerOfTwo(i);
		if (res)
			std::cout << i << "(" << std::bitset<32>(i) << ")" << " is a power of two." << std::endl;
		else 
			std::cout << i << " is not a power of two." << std::endl;
	}
}
