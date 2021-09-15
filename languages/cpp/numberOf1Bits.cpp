#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n);
};

int main(void) {
    Solution solution;
    int input = 11;
    int ans = solution.hammingWeight(input);
    cout << "ans: " << ans << endl;
}

int Solution::hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
        int lastDigit = n & 1;
        if (lastDigit == 1) count++;
        n = n >> 1;
    }
    return count;
}