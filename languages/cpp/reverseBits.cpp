#include <iostream>
using namespace std;
// https://www.cs.cornell.edu/~tomf/notes/cps104/twoscomp.html

class Solution {
public:
    uint32_t reverseBits(uint32_t n);
};

int main(void) {
	Solution solution;
	uint32_t input = 4294967293;
	int ans = solution.reverseBits(input);
	cout << "ans: " << ans << endl;
}

uint32_t Solution::reverseBits(uint32_t n) {

	int ans = 0, temp, lastBit;
	for (int i = 0; i < 32; i++) {
		lastBit = n & 1;
		temp = lastBit << (31 - i);
		ans = ans | temp;
		n >>= 1;
	}
	return ans;

}