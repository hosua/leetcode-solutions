#include <stdint.h>
#include <iostream>
#include <bitset>

#define BIT_MAX 32

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		std::bitset<32> out;
		int j = 0;
		for (int i = BIT_MAX-1; i >= 0; i--, j++)
			out[j] = (n & (1 << i)) ? 1 : 0;
		return out.to_ulong();
    }
};

int main(){
	Solution sol;
	int n = 0b00000010100101000001111010011100;
	int res = sol.reverseBits(n);

	std::cout << "res: " << std::bitset<32>(res) << std::endl;

}
