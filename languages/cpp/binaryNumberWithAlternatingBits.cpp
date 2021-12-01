#include <iostream>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n);
};

int main(void) {
    Solution solution; 
    int n = 5;
    bool ans = solution.hasAlternatingBits(n);
    cout << "ans: " << ans << endl;
}

bool Solution::hasAlternatingBits(int n) {
    if (n == 1) return true;

    int previousBit = n & 1;
    n >>= 1;
    while (n > 0) {
        int lastBit = n & 1;
        if (lastBit == previousBit) return false;
        previousBit = lastBit;
        n >>= 1;
    }

    return true;
}