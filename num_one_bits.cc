#include <stdint.h>
#include <iostream>

#define NUM_BITS 32
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int num_bits = 0;        
		for (int i = 0; i < NUM_BITS; i++)
			if (n & (1 << i))
				num_bits++;
		return num_bits;
    }
};


int main(){
	Solution sol;
	int n = 0b00000000000000000000000000001011;
	int res = sol.hammingWeight(n);
	std::cout << res << std::endl;
}
