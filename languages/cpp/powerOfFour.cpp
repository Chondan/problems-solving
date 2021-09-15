#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n);
    // Bit manipulation
    bool isPowerOfFour2(int n);
};

int main(void) {
    Solution solution;
    int input = 16;
    bool ans = solution.isPowerOfFour2(input);
    cout << "ans: " << ans << endl;
}

bool Solution::isPowerOfFour(int n) {
    if (n == 1) return true;
    if (n % 4 != 0 || n == 0) return false;
    return this->isPowerOfFour(n / 4);
}

// https://leetcode.com/problems/power-of-four/discuss/1320296/C%2B%2B-Bit-manipulation
bool Solution::isPowerOfFour2(int n) {
    if (n <= 0) return false;

    // n is not a power of 2, it can't be power of 4
    if ((n & (n - 1)) != 0) return false;

    // number whose only even bits are set
    // for a number to be power of 4 it should be even power of 2 (2^(2x))
    int bit_field = 0xAAAAAAAA; // ...10101010
    if ((n & bit_field) != 0) return false;

    return true;
}